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



void setup_scr_Main(lv_ui *ui)
{
    //Write codes Main
    ui->Main = lv_obj_create(NULL);
    lv_obj_set_size(ui->Main, 240, 240);
    lv_obj_set_scrollbar_mode(ui->Main, LV_SCROLLBAR_MODE_OFF);

    //Write style for Main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Main, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Main, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui->Main, LV_OBJ_FLAG_SCROLLABLE);

    //Write codes Main_Logo_Img
    ui->Main_Logo_Img = lv_img_create(ui->Main);
    lv_img_set_src(ui->Main_Logo_Img, &_LOGO_alpha_64x64);
    lv_img_set_pivot(ui->Main_Logo_Img, 50,50);
    lv_img_set_angle(ui->Main_Logo_Img, 0);
    lv_obj_set_pos(ui->Main_Logo_Img, 21, 22);
    lv_obj_set_size(ui->Main_Logo_Img, 64, 64);

    //Write style for Main_Logo_Img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Main_Logo_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Main_Logo_Img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Main_Logo_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Main_Logo_Img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Main_Clock_Label
    ui->Main_Clock_Label = lv_label_create(ui->Main);
    lv_label_set_text(ui->Main_Clock_Label, "00:00");
    lv_label_set_long_mode(ui->Main_Clock_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Main_Clock_Label, 110, 30);
    lv_obj_set_size(ui->Main_Clock_Label, 110, 48);

    //Write style for Main_Clock_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Main_Clock_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Main_Clock_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Main_Clock_Label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Main_Clock_Label, &lv_font_Abel_regular_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Main_Clock_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Main_Clock_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Main_Clock_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Main_Clock_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Main_Clock_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Main_Clock_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Main_Clock_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Main_Clock_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Main_Clock_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Main_Clock_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Main_Date_Label
    ui->Main_Date_Label = lv_label_create(ui->Main);
    lv_label_set_text(ui->Main_Date_Label, "0000-00-00  Wednesday\n");
    lv_label_set_long_mode(ui->Main_Date_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Main_Date_Label, 10, 100);
    lv_obj_set_size(ui->Main_Date_Label, 220, 18);

    //Write style for Main_Date_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Main_Date_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Main_Date_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Main_Date_Label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Main_Date_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Main_Date_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Main_Date_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Main_Date_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Main_Date_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Main_Date_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Main_Date_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Main_Date_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Main_Date_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Main_Date_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Main_Date_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Main_HDMI_Cont
    ui->Main_HDMI_Cont = lv_obj_create(ui->Main);
    lv_obj_set_pos(ui->Main_HDMI_Cont, 10, 133);
    lv_obj_set_size(ui->Main_HDMI_Cont, 108, 96);
    lv_obj_set_scrollbar_mode(ui->Main_HDMI_Cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for Main_HDMI_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Main_HDMI_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Main_HDMI_Cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Main_HDMI_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Main_HDMI_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Main_HDMI_Cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Main_HDMI_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Main_HDMI_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Main_HDMI_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Main_HDMI_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Main_HDMI_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Main_HDMI_Img
    ui->Main_HDMI_Img = lv_img_create(ui->Main_HDMI_Cont);
    lv_img_set_src(ui->Main_HDMI_Img, &_HDMI_alpha_64x64);
    lv_img_set_pivot(ui->Main_HDMI_Img, 50,50);
    lv_img_set_angle(ui->Main_HDMI_Img, 0);
    lv_obj_set_pos(ui->Main_HDMI_Img, 22, 0);
    lv_obj_set_size(ui->Main_HDMI_Img, 64, 64);

    //Write style for Main_HDMI_Img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Main_HDMI_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Main_HDMI_Img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Main_HDMI_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Main_HDMI_Img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Main_HDMI_Headline
    ui->Main_HDMI_Headline = lv_label_create(ui->Main_HDMI_Cont);
    lv_label_set_text(ui->Main_HDMI_Headline, "HDMI\n");
    lv_label_set_long_mode(ui->Main_HDMI_Headline, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Main_HDMI_Headline, 20, 64);
    lv_obj_set_size(ui->Main_HDMI_Headline, 64, 16);

    //Write style for Main_HDMI_Headline, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Main_HDMI_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Main_HDMI_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Main_HDMI_Headline, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Main_HDMI_Headline, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Main_HDMI_Headline, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Main_HDMI_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Main_HDMI_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Main_HDMI_Headline, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Main_HDMI_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Main_HDMI_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Main_HDMI_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Main_HDMI_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Main_HDMI_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Main_HDMI_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Main_USB_Cont
    ui->Main_USB_Cont = lv_obj_create(ui->Main);
    lv_obj_set_pos(ui->Main_USB_Cont, 122, 133);
    lv_obj_set_size(ui->Main_USB_Cont, 108, 96);
    lv_obj_set_scrollbar_mode(ui->Main_USB_Cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for Main_USB_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Main_USB_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Main_USB_Cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Main_USB_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Main_USB_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Main_USB_Cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Main_USB_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Main_USB_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Main_USB_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Main_USB_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Main_USB_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Main_USB_Img
    ui->Main_USB_Img = lv_img_create(ui->Main_USB_Cont);
    lv_img_set_src(ui->Main_USB_Img, &_USB_alpha_64x64);
    lv_img_set_pivot(ui->Main_USB_Img, 50,50);
    lv_img_set_angle(ui->Main_USB_Img, 0);
    lv_obj_set_pos(ui->Main_USB_Img, 22, 0);
    lv_obj_set_size(ui->Main_USB_Img, 64, 64);

    //Write style for Main_USB_Img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Main_USB_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Main_USB_Img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Main_USB_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Main_USB_Img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Main_USB_Headline
    ui->Main_USB_Headline = lv_label_create(ui->Main_USB_Cont);
    lv_label_set_text(ui->Main_USB_Headline, "USB");
    lv_label_set_long_mode(ui->Main_USB_Headline, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Main_USB_Headline, 30, 64);
    lv_obj_set_size(ui->Main_USB_Headline, 48, 16);

    //Write style for Main_USB_Headline, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Main_USB_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Main_USB_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Main_USB_Headline, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Main_USB_Headline, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Main_USB_Headline, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Main_USB_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Main_USB_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Main_USB_Headline, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Main_USB_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Main_USB_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Main_USB_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Main_USB_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Main_USB_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Main_USB_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Main.


    //Update current screen layout.
    lv_obj_update_layout(ui->Main);

    //Init events for screen.
    events_init_Main(ui);
}
