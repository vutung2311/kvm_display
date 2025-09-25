#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "kvmui/gui_guider.h"
#include "screen.h"
#include "ctrl.h"

typedef struct {
    unsigned long long received_bytes;
    unsigned long long sent_bytes;
} NetworkStats;

typedef struct {
    bool USB_connected;
    bool HDMI_connected;
    bool Network_connected;
} connect_state_t;

extern int cpu_usage;
extern int ram_usage;
//int running = 1;
extern lv_ui guider_ui;
extern connect_state_t connect_state;

int get_cpu_usage();
int get_ram_usage();

void startupdate();
void stopupdate();
static void update_ui_timer(lv_timer_t * timer);
void* run_monitor_loop(void* arg);

void get_current_date_weekday_str(char* buffer, size_t size);
void get_current_time_str(char* buffer, size_t size) ;
