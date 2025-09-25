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



void setup_scr_Version(lv_ui *ui)
{
    //Write codes Version
    ui->Version = lv_obj_create(NULL);
    lv_obj_set_size(ui->Version, 240, 240);
    lv_obj_set_scrollbar_mode(ui->Version, LV_SCROLLBAR_MODE_OFF);

    //Write style for Version, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Version, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Version, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Version, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui->Version, LV_OBJ_FLAG_SCROLLABLE);

    //Write codes Version_ui_Version_cont
    ui->Version_ui_Version_cont = lv_obj_create(ui->Version);
    lv_obj_set_pos(ui->Version_ui_Version_cont, 10, 10);
    lv_obj_set_size(ui->Version_ui_Version_cont, 220, 220);
    lv_obj_set_scrollbar_mode(ui->Version_ui_Version_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for Version_ui_Version_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Version_ui_Version_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Version_ui_Version_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Version_ui_Version_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Version_ui_Version_cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Version_ui_Version_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Version_ui_Version_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Version_ui_Version_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Version_ui_Version_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Version_ui_Version_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Version_ui_Version_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Version_Logo_Img
    ui->Version_Logo_Img = lv_img_create(ui->Version_ui_Version_cont);
    lv_img_set_src(ui->Version_Logo_Img, &_LOGO_alpha_64x64);
    lv_img_set_pivot(ui->Version_Logo_Img, 50,50);
    lv_img_set_angle(ui->Version_Logo_Img, 0);
    lv_obj_set_pos(ui->Version_Logo_Img, 78, 18);
    lv_obj_set_size(ui->Version_Logo_Img, 64, 64);

    //Write style for Version_Logo_Img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Version_Logo_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Version_Logo_Img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Version_Logo_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Version_Logo_Img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Version_Hostname_Headline
    ui->Version_Hostname_Headline = lv_label_create(ui->Version_ui_Version_cont);
    lv_label_set_text(ui->Version_Hostname_Headline, "Hostname");
    lv_label_set_long_mode(ui->Version_Hostname_Headline, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Version_Hostname_Headline, 20, 164);
    lv_obj_set_size(ui->Version_Hostname_Headline, 160, 16);

    //Write style for Version_Hostname_Headline, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Version_Hostname_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Version_Hostname_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Version_Hostname_Headline, lv_color_hex(0x7e7e7e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Version_Hostname_Headline, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Version_Hostname_Headline, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Version_Hostname_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Version_Hostname_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Version_Hostname_Headline, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Version_Hostname_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Version_Hostname_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Version_Hostname_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Version_Hostname_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Version_Hostname_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Version_Hostname_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Version_Hostname_Label
    ui->Version_Hostname_Label = lv_label_create(ui->Version_ui_Version_cont);
    lv_label_set_text(ui->Version_Hostname_Label, "Unknown\n");
    lv_label_set_long_mode(ui->Version_Hostname_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Version_Hostname_Label, 20, 188);
    lv_obj_set_size(ui->Version_Hostname_Label, 160, 16);

    //Write style for Version_Hostname_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Version_Hostname_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Version_Hostname_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Version_Hostname_Label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Version_Hostname_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Version_Hostname_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Version_Hostname_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Version_Hostname_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Version_Hostname_Label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Version_Hostname_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Version_Hostname_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Version_Hostname_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Version_Hostname_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Version_Hostname_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Version_Hostname_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Version_Line
    ui->Version_Line = lv_line_create(ui->Version_ui_Version_cont);
    static lv_point_t Version_Line[] = {{0, 0},{180, 0},};
    lv_line_set_points(ui->Version_Line, Version_Line, 2);
    lv_obj_set_pos(ui->Version_Line, 20, 150);
    lv_obj_set_size(ui->Version_Line, 180, 1);

    //Write style for Version_Line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Version_Line, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Version_Line, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Version_Line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Version_Line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Version_App_Version_Headline
    ui->Version_App_Version_Headline = lv_label_create(ui->Version_ui_Version_cont);
    lv_label_set_text(ui->Version_App_Version_Headline, "App Version");
    lv_label_set_long_mode(ui->Version_App_Version_Headline, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Version_App_Version_Headline, 20, 100);
    lv_obj_set_size(ui->Version_App_Version_Headline, 180, 16);

    //Write style for Version_App_Version_Headline, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Version_App_Version_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Version_App_Version_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Version_App_Version_Headline, lv_color_hex(0x7e7e7e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Version_App_Version_Headline, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Version_App_Version_Headline, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Version_App_Version_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Version_App_Version_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Version_App_Version_Headline, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Version_App_Version_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Version_App_Version_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Version_App_Version_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Version_App_Version_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Version_App_Version_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Version_App_Version_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Version_App_Version_Label
    ui->Version_App_Version_Label = lv_label_create(ui->Version_ui_Version_cont);
    lv_label_set_text(ui->Version_App_Version_Label, "0.0.0");
    lv_label_set_long_mode(ui->Version_App_Version_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Version_App_Version_Label, 20, 124);
    lv_obj_set_size(ui->Version_App_Version_Label, 160, 15);

    //Write style for Version_App_Version_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Version_App_Version_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Version_App_Version_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Version_App_Version_Label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Version_App_Version_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Version_App_Version_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Version_App_Version_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Version_App_Version_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Version_App_Version_Label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Version_App_Version_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Version_App_Version_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Version_App_Version_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Version_App_Version_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Version_App_Version_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Version_App_Version_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Version.


    //Update current screen layout.
    lv_obj_update_layout(ui->Version);

    //Init events for screen.
    events_init_Version(ui);
}
