/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void Main_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.Monitor, guider_ui.Monitor_del, &guider_ui.Main_del, setup_scr_Monitor, LV_SCR_LOAD_ANIM_MOVE_LEFT, 100, 100, false, false);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.Version, guider_ui.Version_del, &guider_ui.Main_del, setup_scr_Version, LV_SCR_LOAD_ANIM_OVER_RIGHT, 100, 100, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_Main (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Main, Main_event_handler, LV_EVENT_ALL, ui);
}

static void Monitor_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.Main, guider_ui.Main_del, &guider_ui.Monitor_del, setup_scr_Main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, false, false);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.Network, guider_ui.Network_del, &guider_ui.Monitor_del, setup_scr_Network, LV_SCR_LOAD_ANIM_MOVE_LEFT, 100, 100, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_Monitor (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Monitor, Monitor_event_handler, LV_EVENT_ALL, ui);
}

static void Network_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.Monitor, guider_ui.Monitor_del, &guider_ui.Network_del, setup_scr_Monitor, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, false, false);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.Version, guider_ui.Version_del, &guider_ui.Network_del, setup_scr_Version, LV_SCR_LOAD_ANIM_MOVE_LEFT, 100, 100, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_Network (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Network, Network_event_handler, LV_EVENT_ALL, ui);
}

static void Version_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.Network, guider_ui.Network_del, &guider_ui.Version_del, setup_scr_Network, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 100, false, false);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.Main, guider_ui.Main_del, &guider_ui.Version_del, setup_scr_Main, LV_SCR_LOAD_ANIM_OVER_LEFT, 100, 100, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_Version (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Version, Version_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
