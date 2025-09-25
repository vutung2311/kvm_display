#include "update.h"
#include <time.h>
#include <locale.h>

int cpu_usage;
int ram_usage;
int cpu_temp;
double download, upload;
char time_str[16];
char date_week_str[32];

connect_state_t connect_state;

//pthread_mutex_t data_mutex = PTHREAD_MUTEX_INITIALIZER;

void get_current_time_str(char* buffer, size_t size) 
{
    //setenv("TZ", "CST-8", 1);
    //tzset();

    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);

    strftime(buffer, size, "%H:%M", tm_info);
}

void get_current_date_weekday_str(char* buffer, size_t size) 
{
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);


    char* old_locale = setlocale(LC_TIME, "C");

    strftime(buffer, size, "%Y-%m-%d %A", tm_info);
 
    if (old_locale) {
        setlocale(LC_TIME, old_locale);
    }
}

int get_network_stats(const char* interface, NetworkStats* stats) 
{
    FILE* file = fopen("/proc/net/dev", "r");
    if (!file) {
        perror("Failed to open /proc/net/dev");
        return -1;
    }

    char line[256];
    int found = 0;


    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file))
    {

        char* name = line;
        while (*name == ' ') name++;


        char* colon = strchr(name, ':');
        if (!colon) continue;

        *colon = '\0';  

        if (strcmp(name, interface) == 0) {

            if (sscanf(colon + 1, "%llu %*u %*u %*u %*u %*u %*u %*u %llu",
                       &stats->received_bytes, &stats->sent_bytes) == 2) {
                found = 1;
                break;
            }
        }
    }

    fclose(file);
    return found ? 0 : -1;
}

void get_network_speed(const char* interface, double* download, double* upload) 
{
    static NetworkStats prev_stats = {0};
    static struct timespec prev_time = {0};

    NetworkStats curr_stats;
    struct timespec curr_time;
    if (get_network_stats(interface, &curr_stats))
    {
        *download = *upload = -1.0;
        return;
    }

    clock_gettime(CLOCK_MONOTONIC, &curr_time);

    if (prev_stats.received_bytes == 0 || prev_stats.sent_bytes == 0) {

        prev_stats = curr_stats;
        prev_time = curr_time;
        *download = *upload = 0.0;
        return;
    }


    double time_diff = (curr_time.tv_sec - prev_time.tv_sec) +
                      (curr_time.tv_nsec - prev_time.tv_nsec) / 1e9;

    if (time_diff < 0.1) {  
        *download = *upload = 0.0;
        return;
    }


    unsigned long long received_diff = curr_stats.received_bytes - prev_stats.received_bytes;
    unsigned long long sent_diff = curr_stats.sent_bytes - prev_stats.sent_bytes;

    *download = (received_diff * 8.0) / (time_diff * 1000000.0);
    *upload = (sent_diff * 8.0) / (time_diff * 1000000.0);

    prev_stats = curr_stats;
    prev_time = curr_time;
}



int get_cpu_usage() 
{
    FILE* file;
    unsigned long long user, nice, system, idle, iowait, irq, softirq;
    unsigned long long total_time, idle_time, total_diff, idle_diff;
    static unsigned long long prev_total = 0, prev_idle = 0;
    int usage = 0;

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("open failed/proc/stat");
        return -1;
    }
    fscanf(file, "cpu %llu %llu %llu %llu %llu %llu %llu", 
           &user, &nice, &system, &idle, &iowait, &irq, &softirq);
    fclose(file);

    total_time = user + nice + system + idle + iowait + irq + softirq;
    idle_time = idle;

    if (prev_total == 0 || prev_idle == 0) {
        prev_total = total_time;
        prev_idle = idle_time;
        sleep(1);

        file = fopen("/proc/stat", "r");
        fscanf(file, "cpu %llu %llu %llu %llu %llu %llu %llu", 
               &user, &nice, &system, &idle, &iowait, &irq, &softirq);
        fclose(file);

        total_time = user + nice + system + idle + iowait + irq + softirq;
        idle_time = idle;
    }

    total_diff = total_time - prev_total;
    idle_diff = idle_time - prev_idle;

    if (total_diff > 0) {
        usage = (int)(100.0 * (1.0 - (double)idle_diff / (double)total_diff) + 0.5);
    }

    prev_total = total_time;
    prev_idle = idle_time;    
    return usage;
}

int get_cpu_temperature() 
{
    FILE* file;
    int raw_temp; 

    file = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (file == NULL) {
        perror("Failed to open temperature file");
        return -1;
    }

    if (fscanf(file, "%d", &raw_temp) != 1) {
        perror("Failed to read temperature value");
        fclose(file);
        return -1;
    }
    fclose(file);

    int celsius = (raw_temp + 50) / 1000;

    return celsius;
}

int get_ram_usage() 
{
    FILE* file;
    char line[128];
    int usage = 0;

    FILE* pipe = popen("free | awk '/Mem:/ {printf(\"%d\\n\", $3/$2*100)}'", "r");
    if (pipe == NULL) {
        perror("popen failed");
        return -1;
    }

    if (fgets(line, sizeof(line), pipe) != NULL) {
        sscanf(line, "%d", &usage);
    }

    pclose(pipe);

    return usage;
}

void* run_monitor_loop(void* arg) {
    (void)arg;
    
    while (1) {
        cpu_usage = get_cpu_usage();
        ram_usage = get_ram_usage();
        cpu_temp = get_cpu_temperature();
        get_network_speed("eth0", &download, &upload);
        get_current_time_str(time_str, sizeof(time_str));
        get_current_date_weekday_str(date_week_str, sizeof(date_week_str));

        fflush(stdout);
        sleep(1);
    }

    return NULL;
}


static void update_ui_timer(lv_timer_t * timer) {
    (void)timer;

    int cpu, ram,temp;
    double down,up;
    bool components_valid = 
        guider_ui.Monitor_CPU_Used_Arc && 
        lv_obj_is_valid(guider_ui.Monitor_CPU_Used_Arc) &&
        guider_ui.Monitor_CPU_Used_Label &&
        lv_obj_is_valid(guider_ui.Monitor_CPU_Used_Label) &&
        guider_ui.Monitor_RAM_Used_Arc && 
        lv_obj_is_valid(guider_ui.Monitor_RAM_Used_Arc) &&
        guider_ui.Monitor_RAM_Used_Label&&
        lv_obj_is_valid(guider_ui.Monitor_RAM_Used_Label);
    
    if (!components_valid) return;

    //pthread_mutex_lock(&data_mutex);
    cpu = cpu_usage;
    ram = ram_usage;
    temp = cpu_temp;
    down = download;
    up = upload;
    //pthread_mutex_unlock(&data_mutex);

    if (guider_ui.Monitor_CPU_Used_Arc) {
        lv_arc_set_value(guider_ui.Monitor_CPU_Used_Arc, cpu);
    }

    if (guider_ui.Monitor_RAM_Used_Arc) {
        lv_arc_set_value(guider_ui.Monitor_RAM_Used_Arc, ram);
    }

    if (guider_ui.Monitor_CPU_Used_Label) {
        char text[16];
        snprintf(text, sizeof(text), "%d", cpu);
        lv_label_set_text(guider_ui.Monitor_CPU_Used_Label, text);
    }

    if (guider_ui.Monitor_RAM_Used_Label) {
        char text[16];
        snprintf(text, sizeof(text), "%d", ram);
        lv_label_set_text(guider_ui.Monitor_RAM_Used_Label, text);
    }

    if(guider_ui.Monitor_CPU_Temp_Label){
        char text[16];
        snprintf(text, sizeof(text), "%d°C", temp);
        lv_label_set_text(guider_ui.Monitor_CPU_Temp_Label, text);
    }

    if(guider_ui.Monitor_Net_Up_Label)
    {
        char text[16];
        snprintf(text, sizeof(text), LV_SYMBOL_UPLOAD" %.2f Mb", up);
        lv_label_set_text(guider_ui.Monitor_Net_Up_Label, text);
    }

    if(guider_ui.Monitor_Net_Down_Label)
    {
        char text[16];
        snprintf(text, sizeof(text), LV_SYMBOL_DOWNLOAD" %.2f Mb", down);
        lv_label_set_text(guider_ui.Monitor_Net_Down_Label, text);
    }

    if(guider_ui.Main_Clock_Label)
    {
        lv_label_set_text(guider_ui.Main_Clock_Label,time_str);
    }

    if(guider_ui.Main_Date_Label)
    {
        lv_label_set_text(guider_ui.Main_Date_Label,date_week_str);
    }

    if (guider_ui.Main_USB_Cont)
    {
        if (connect_state.USB_connected)
            lv_obj_set_style_bg_color(guider_ui.Main_USB_Cont, lv_color_hex(0x0080ff), LV_PART_MAIN|LV_STATE_DEFAULT);
        else
            lv_obj_set_style_bg_color(guider_ui.Main_USB_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    }

    if (guider_ui.Main_HDMI_Cont)
    {
        if (connect_state.HDMI_connected)
            lv_obj_set_style_bg_color(guider_ui.Main_HDMI_Cont, lv_color_hex(0x0080ff), LV_PART_MAIN|LV_STATE_DEFAULT);
        else
            lv_obj_set_style_bg_color(guider_ui.Main_HDMI_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    }
}

void startupdate()
{
    lv_timer_create(update_ui_timer, 1000, NULL);
}

void stopupdate()
{

}

