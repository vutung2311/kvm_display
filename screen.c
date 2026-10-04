#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

#include "screen.h"
#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"

#include "kvmui/gui_guider.h"
#include "ui_index.h"

#include "kvmui/events_init.h"
#include "update.h"

char time_str1[16];
char date_week_str1[32];


#define DISP_BUF_SIZE (240 * 240)
static lv_color_t buf[DISP_BUF_SIZE];
static lv_disp_draw_buf_t disp_buf;
static lv_disp_drv_t disp_drv;
static lv_indev_drv_t indev_drv;

void init_lvgl() {
    lv_init();
    fbdev_init();
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.ver_res = 240;
    disp_drv.hor_res = 240;
    disp_drv.rotated = LV_DISP_ROT_180;
    disp_drv.sw_rotate = true;
    // disp_drv.full_refresh = true;

    lv_disp_drv_register(&disp_drv);

    evdev_init();
    evdev_set_file("/dev/input/event0");

    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = evdev_read;
    lv_indev_drv_register(&indev_drv);
 
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    get_current_time_str(time_str1, sizeof(time_str1));
    get_current_date_weekday_str(date_week_str1, sizeof(date_week_str1));

    if(guider_ui.Main_Clock_Label)
    {
        lv_label_set_text(guider_ui.Main_Clock_Label,time_str1);
    }

    if(guider_ui.Main_Date_Label)
    {
        lv_label_set_text(guider_ui.Main_Date_Label,date_week_str1);
    }    
    startupdate();

}

void *run_lvgl_loop(void *arg) {
    while(1) {
        lv_timer_handler();
        usleep(10000);
    }
}

uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}

lv_obj_t *ui_get_obj(const char *name) {
    for (size_t i = 0; i < ui_objects_size; i++) {
        if (strcmp(ui_objects[i].name, name) == 0) {
            return *ui_objects[i].obj;
        }
    }
    return NULL;
}

void ui_set_text(const char *name, const char *text) {
    lv_obj_t *obj = ui_get_obj(name);
    if(obj == NULL) {
        //printf("[kvm_display] ui_set_text %s %s, obj not found\n", name, text);
        return;
    }
    lv_label_set_text(obj, text);
}

void ui_set_network() {
    if(guider_ui.Network_No_Network_Cont)
        lv_obj_add_flag(guider_ui.Network_No_Network_Cont, LV_OBJ_FLAG_HIDDEN);
    if(guider_ui.Network_Address_Cont)
        lv_obj_clear_flag(guider_ui.Network_Address_Cont, LV_OBJ_FLAG_HIDDEN);
    if(guider_ui.Network_ZeroTier_Cont)
        lv_obj_clear_flag(guider_ui.Network_ZeroTier_Cont, LV_OBJ_FLAG_HIDDEN);
    if(guider_ui.Network_TailScale_Cont)
        lv_obj_clear_flag(guider_ui.Network_TailScale_Cont, LV_OBJ_FLAG_HIDDEN);
}

void ui_set_no_network() {
    if(guider_ui.Network_No_Network_Cont)
        lv_obj_clear_flag(guider_ui.Network_No_Network_Cont, LV_OBJ_FLAG_HIDDEN);
    if(guider_ui.Network_Address_Cont)
        lv_obj_add_flag(guider_ui.Network_Address_Cont, LV_OBJ_FLAG_HIDDEN);
    if(guider_ui.Network_ZeroTier_Cont)
        lv_obj_add_flag(guider_ui.Network_ZeroTier_Cont, LV_OBJ_FLAG_HIDDEN);
    if(guider_ui.Network_TailScale_Cont)
        lv_obj_add_flag(guider_ui.Network_TailScale_Cont, LV_OBJ_FLAG_HIDDEN);
}