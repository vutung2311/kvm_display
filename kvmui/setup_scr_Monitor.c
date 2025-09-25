/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_Monitor(lv_ui *ui)
{
    //Write codes Monitor
    ui->Monitor = lv_obj_create(NULL);
    lv_obj_set_size(ui->Monitor, 240, 240);
    lv_obj_set_scrollbar_mode(ui->Monitor, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Monitor, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    //Write style for Monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui->Monitor, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);

    //Write codes Monitor_CPU_Used_Cont
    ui->Monitor_CPU_Used_Cont = lv_obj_create(ui->Monitor);
    lv_obj_set_pos(ui->Monitor_CPU_Used_Cont, 10, 10);
    lv_obj_set_size(ui->Monitor_CPU_Used_Cont, 108, 106);
    lv_obj_set_scrollbar_mode(ui->Monitor_CPU_Used_Cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(ui->Monitor_CPU_Used_Cont, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);

    //Write style for Monitor_CPU_Used_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_CPU_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_CPU_Used_Cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_CPU_Used_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_CPU_Used_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_CPU_Used_Cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_CPU_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_CPU_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_CPU_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_CPU_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_CPU_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_CPU_Used_Headline
    ui->Monitor_CPU_Used_Headline = lv_label_create(ui->Monitor_CPU_Used_Cont);
    lv_label_set_text(ui->Monitor_CPU_Used_Headline, "CPU Used\n");
    lv_label_set_long_mode(ui->Monitor_CPU_Used_Headline, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_CPU_Used_Headline, 0, 10);
    lv_obj_set_size(ui->Monitor_CPU_Used_Headline, 108, 16);

    //Write style for Monitor_CPU_Used_Headline, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_CPU_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_CPU_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_CPU_Used_Headline, lv_color_hex(0x7e7e7e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_CPU_Used_Headline, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_CPU_Used_Headline, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_CPU_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_CPU_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_CPU_Used_Headline, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_CPU_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_CPU_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_CPU_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_CPU_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_CPU_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_CPU_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_CPU_Used_Arc
    ui->Monitor_CPU_Used_Arc = lv_arc_create(ui->Monitor_CPU_Used_Cont);
    lv_arc_set_mode(ui->Monitor_CPU_Used_Arc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Monitor_CPU_Used_Arc, 0, 100);
    lv_arc_set_bg_angles(ui->Monitor_CPU_Used_Arc, 0, 360);
    lv_arc_set_value(ui->Monitor_CPU_Used_Arc, 0);
    lv_arc_set_rotation(ui->Monitor_CPU_Used_Arc, 270);
    lv_obj_set_pos(ui->Monitor_CPU_Used_Arc, 4, 13);
    lv_obj_set_size(ui->Monitor_CPU_Used_Arc, 100, 100);
    lv_obj_clear_flag(ui->Monitor_CPU_Used_Arc, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);

    //Write style for Monitor_CPU_Used_Arc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_CPU_Used_Arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Monitor_CPU_Used_Arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Monitor_CPU_Used_Arc, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Monitor_CPU_Used_Arc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Monitor_CPU_Used_Arc, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_CPU_Used_Arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_CPU_Used_Arc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_CPU_Used_Arc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_CPU_Used_Arc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_CPU_Used_Arc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_CPU_Used_Arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Monitor_CPU_Used_Arc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Monitor_CPU_Used_Arc, 11, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Monitor_CPU_Used_Arc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Monitor_CPU_Used_Arc, lv_color_hex(0xff6500), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Monitor_CPU_Used_Arc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    //lv_obj_set_style_bg_opa(ui->Monitor_CPU_Used_Arc, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(ui->Monitor_CPU_Used_Arc, lv_color_hex(0xff6500), LV_PART_KNOB|LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_grad_dir(ui->Monitor_CPU_Used_Arc, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    //lv_obj_set_style_pad_all(ui->Monitor_CPU_Used_Arc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_remove_style(ui->Monitor_CPU_Used_Arc, NULL, LV_PART_KNOB);

    //Write codes Monitor_CPU_Used_Label
    ui->Monitor_CPU_Used_Label = lv_label_create(ui->Monitor_CPU_Used_Cont);
    lv_label_set_text(ui->Monitor_CPU_Used_Label, "0");
    lv_label_set_long_mode(ui->Monitor_CPU_Used_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_CPU_Used_Label, 30, 55);
    lv_obj_set_size(ui->Monitor_CPU_Used_Label, 48, 16);

    //Write style for Monitor_CPU_Used_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_CPU_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_CPU_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_CPU_Used_Label, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_CPU_Used_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_CPU_Used_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_CPU_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_CPU_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_CPU_Used_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_CPU_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_CPU_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_CPU_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_CPU_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_CPU_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_CPU_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_RAM_Used_Cont
    ui->Monitor_RAM_Used_Cont = lv_obj_create(ui->Monitor);
    lv_obj_set_pos(ui->Monitor_RAM_Used_Cont, 122, 10);
    lv_obj_set_size(ui->Monitor_RAM_Used_Cont, 108, 106);
    lv_obj_set_scrollbar_mode(ui->Monitor_RAM_Used_Cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(ui->Monitor_RAM_Used_Cont, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);

    //Write style for Monitor_RAM_Used_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_RAM_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_RAM_Used_Cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_RAM_Used_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_RAM_Used_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_RAM_Used_Cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_RAM_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_RAM_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_RAM_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_RAM_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_RAM_Used_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_RAM_Used_Headline
    ui->Monitor_RAM_Used_Headline = lv_label_create(ui->Monitor_RAM_Used_Cont);
    lv_label_set_text(ui->Monitor_RAM_Used_Headline, "RAM Used\n");
    lv_label_set_long_mode(ui->Monitor_RAM_Used_Headline, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_RAM_Used_Headline, 0, 10);
    lv_obj_set_size(ui->Monitor_RAM_Used_Headline, 108, 16);

    //Write style for Monitor_RAM_Used_Headline, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_RAM_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_RAM_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_RAM_Used_Headline, lv_color_hex(0x7e7e7e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_RAM_Used_Headline, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_RAM_Used_Headline, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_RAM_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_RAM_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_RAM_Used_Headline, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_RAM_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_RAM_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_RAM_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_RAM_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_RAM_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_RAM_Used_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_RAM_Used_Arc
    ui->Monitor_RAM_Used_Arc = lv_arc_create(ui->Monitor_RAM_Used_Cont);
    lv_arc_set_mode(ui->Monitor_RAM_Used_Arc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Monitor_RAM_Used_Arc, 0, 100);
    lv_arc_set_bg_angles(ui->Monitor_RAM_Used_Arc, 0, 360);
    lv_arc_set_value(ui->Monitor_RAM_Used_Arc, 0);
    lv_arc_set_rotation(ui->Monitor_RAM_Used_Arc, 270);
    lv_obj_set_pos(ui->Monitor_RAM_Used_Arc, 4, 13);
    lv_obj_set_size(ui->Monitor_RAM_Used_Arc, 100, 100);
    lv_obj_clear_flag(ui->Monitor_RAM_Used_Arc, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);

    //Write style for Monitor_RAM_Used_Arc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_RAM_Used_Arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Monitor_RAM_Used_Arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Monitor_RAM_Used_Arc, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Monitor_RAM_Used_Arc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Monitor_RAM_Used_Arc, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_RAM_Used_Arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_RAM_Used_Arc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_RAM_Used_Arc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_RAM_Used_Arc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_RAM_Used_Arc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_RAM_Used_Arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Monitor_RAM_Used_Arc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Monitor_RAM_Used_Arc, 11, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Monitor_RAM_Used_Arc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Monitor_RAM_Used_Arc, lv_color_hex(0x00DFFF), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Monitor_RAM_Used_Arc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    //lv_obj_set_style_bg_opa(ui->Monitor_RAM_Used_Arc, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(ui->Monitor_RAM_Used_Arc, lv_color_hex(0x00DFFF), LV_PART_KNOB|LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_grad_dir(ui->Monitor_RAM_Used_Arc, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    //lv_obj_set_style_pad_all(ui->Monitor_RAM_Used_Arc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_remove_style(ui->Monitor_RAM_Used_Arc, NULL, LV_PART_KNOB);

    //Write codes Monitor_RAM_Used_Label
    ui->Monitor_RAM_Used_Label = lv_label_create(ui->Monitor_RAM_Used_Cont);
    lv_label_set_text(ui->Monitor_RAM_Used_Label, "0");
    lv_label_set_long_mode(ui->Monitor_RAM_Used_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_RAM_Used_Label, 30, 55);
    lv_obj_set_size(ui->Monitor_RAM_Used_Label, 48, 16);

    //Write style for Monitor_RAM_Used_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_RAM_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_RAM_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_RAM_Used_Label, lv_color_hex(0x00DFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_RAM_Used_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_RAM_Used_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_RAM_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_RAM_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_RAM_Used_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_RAM_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_RAM_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_RAM_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_RAM_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_RAM_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_RAM_Used_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_CPU_Temp_Cont
    ui->Monitor_CPU_Temp_Cont = lv_obj_create(ui->Monitor);
    lv_obj_set_pos(ui->Monitor_CPU_Temp_Cont, 10, 120);
    lv_obj_set_size(ui->Monitor_CPU_Temp_Cont, 220, 40);
    lv_obj_set_scrollbar_mode(ui->Monitor_CPU_Temp_Cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for Monitor_CPU_Temp_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_CPU_Temp_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_CPU_Temp_Cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_CPU_Temp_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_CPU_Temp_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_CPU_Temp_Cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_CPU_Temp_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_CPU_Temp_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_CPU_Temp_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_CPU_Temp_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_CPU_Temp_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_CPU_Temp_Headline
    ui->Monitor_CPU_Temp_Headline = lv_label_create(ui->Monitor_CPU_Temp_Cont);
    lv_label_set_text(ui->Monitor_CPU_Temp_Headline, "CPU Temp");
    lv_label_set_long_mode(ui->Monitor_CPU_Temp_Headline, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_CPU_Temp_Headline, 0, 12);
    lv_obj_set_size(ui->Monitor_CPU_Temp_Headline, 110, 16);

    //Write style for Monitor_CPU_Temp_Headline, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_CPU_Temp_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_CPU_Temp_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_CPU_Temp_Headline, lv_color_hex(0x7e7e7e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_CPU_Temp_Headline, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_CPU_Temp_Headline, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_CPU_Temp_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_CPU_Temp_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_CPU_Temp_Headline, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_CPU_Temp_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_CPU_Temp_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_CPU_Temp_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_CPU_Temp_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_CPU_Temp_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_CPU_Temp_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_CPU_Temp_Label
    ui->Monitor_CPU_Temp_Label = lv_label_create(ui->Monitor_CPU_Temp_Cont);
    lv_label_set_text(ui->Monitor_CPU_Temp_Label, "0°C");
    lv_label_set_long_mode(ui->Monitor_CPU_Temp_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_CPU_Temp_Label, 110, 12);
    lv_obj_set_size(ui->Monitor_CPU_Temp_Label, 110, 16);

    //Write style for Monitor_CPU_Temp_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_CPU_Temp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_CPU_Temp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_CPU_Temp_Label, lv_color_hex(0xf99200), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_CPU_Temp_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_CPU_Temp_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_CPU_Temp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_CPU_Temp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_CPU_Temp_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_CPU_Temp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_CPU_Temp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_CPU_Temp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_CPU_Temp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_CPU_Temp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_CPU_Temp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_Net_Cont
    ui->Monitor_Net_Cont = lv_obj_create(ui->Monitor);
    lv_obj_set_pos(ui->Monitor_Net_Cont, 10, 164);
    lv_obj_set_size(ui->Monitor_Net_Cont, 220, 66);
    lv_obj_set_scrollbar_mode(ui->Monitor_Net_Cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(ui->Monitor_Net_Cont, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);

    //Write style for Monitor_Net_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_Net_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_Net_Cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_Net_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_Net_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_Net_Cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_Net_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_Net_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_Net_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_Net_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_Net_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_Net_Img
    ui->Monitor_Net_Img = lv_img_create(ui->Monitor_Net_Cont);
    lv_img_set_src(ui->Monitor_Net_Img, &_net_alpha_64x64);
    lv_img_set_pivot(ui->Monitor_Net_Img, 50,50);
    lv_img_set_angle(ui->Monitor_Net_Img, 0);
    lv_obj_set_pos(ui->Monitor_Net_Img, 10, 1);
    lv_obj_set_size(ui->Monitor_Net_Img, 64, 64);

    //Write style for Monitor_Net_Img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Monitor_Net_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Monitor_Net_Img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_Net_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Monitor_Net_Img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_Net_Up_Img
    //ui->Monitor_Net_Up_Img = lv_img_create(ui->Monitor_Net_Cont);
    //lv_img_set_src(ui->Monitor_Net_Up_Img, &_up_alpha_20x20);
    //lv_img_set_pivot(ui->Monitor_Net_Up_Img, 50,50);
    //lv_img_set_angle(ui->Monitor_Net_Up_Img, 0);
    //lv_obj_set_pos(ui->Monitor_Net_Up_Img, 92, 11);
    //lv_obj_set_size(ui->Monitor_Net_Up_Img, 20, 20);

    //Write style for Monitor_Net_Up_Img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    //lv_obj_set_style_img_recolor_opa(ui->Monitor_Net_Up_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    //lv_obj_set_style_img_opa(ui->Monitor_Net_Up_Img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    //lv_obj_set_style_radius(ui->Monitor_Net_Up_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    //lv_obj_set_style_clip_corner(ui->Monitor_Net_Up_Img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_Net_Up_Label
    ui->Monitor_Net_Up_Label = lv_label_create(ui->Monitor_Net_Cont);
    lv_label_set_text(ui->Monitor_Net_Up_Label, LV_SYMBOL_UP" 000.00 Mb");
    lv_label_set_long_mode(ui->Monitor_Net_Up_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_Net_Up_Label, 90, 13);
    lv_obj_set_size(ui->Monitor_Net_Up_Label, 130, 16);

    //Write style for Monitor_Net_Up_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_Net_Up_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_Net_Up_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_Net_Up_Label, lv_color_hex(0x00F7A3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_Net_Up_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_Net_Up_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_Net_Up_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_Net_Up_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_Net_Up_Label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_Net_Up_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_Net_Up_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_Net_Up_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_Net_Up_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_Net_Up_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_Net_Up_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_Net_Down_Img
    //ui->Monitor_Net_Down_Img = lv_img_create(ui->Monitor_Net_Cont);
    //lv_img_set_src(ui->Monitor_Net_Down_Img, &_up_alpha_20x20);
    //lv_img_set_pivot(ui->Monitor_Net_Down_Img, 10,10);
    //lv_img_set_angle(ui->Monitor_Net_Down_Img, 1800);
    //lv_obj_set_pos(ui->Monitor_Net_Down_Img, 92, 35);
    //lv_obj_set_size(ui->Monitor_Net_Down_Img, 20, 20);

    //Write style for Monitor_Net_Down_Img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    //lv_obj_set_style_img_recolor_opa(ui->Monitor_Net_Down_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    //lv_obj_set_style_img_opa(ui->Monitor_Net_Down_Img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    //lv_obj_set_style_radius(ui->Monitor_Net_Down_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    //lv_obj_set_style_clip_corner(ui->Monitor_Net_Down_Img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_Net_Down_Label
    ui->Monitor_Net_Down_Label = lv_label_create(ui->Monitor_Net_Cont);
    lv_label_set_text(ui->Monitor_Net_Down_Label, LV_SYMBOL_DOWN" 000.00 Mb\n");
    lv_label_set_long_mode(ui->Monitor_Net_Down_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_Net_Down_Label, 90, 37);
    lv_obj_set_size(ui->Monitor_Net_Down_Label, 130, 16);

    //Write style for Monitor_Net_Down_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_Net_Down_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_Net_Down_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_Net_Down_Label, lv_color_hex(0x00F7A3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_Net_Down_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_Net_Down_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_Net_Down_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_Net_Down_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_Net_Down_Label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_Net_Down_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_Net_Down_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_Net_Down_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_Net_Down_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_Net_Down_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_Net_Down_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Monitor.


    //Update current screen layout.
    lv_obj_update_layout(ui->Monitor);

    //Init events for screen.
    events_init_Monitor(ui);
}
