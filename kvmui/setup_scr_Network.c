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



void setup_scr_Network(lv_ui *ui)
{
    //Write codes Network
    ui->Network = lv_obj_create(NULL);
    lv_obj_set_size(ui->Network, 240, 240);
    lv_obj_set_scrollbar_mode(ui->Network, LV_SCROLLBAR_MODE_OFF);

    //Write style for Network, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Network, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Network, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Network, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui->Network, LV_OBJ_FLAG_SCROLLABLE);

    //Write codes Network_Address_Cont
    ui->Network_Address_Cont = lv_obj_create(ui->Network);
    lv_obj_set_pos(ui->Network_Address_Cont, 10, 10);
    lv_obj_set_size(ui->Network_Address_Cont, 220, 132);
    lv_obj_set_scrollbar_mode(ui->Network_Address_Cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(ui->Network_Address_Cont, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);

    //Write style for Network_Address_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_Address_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_Address_Cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_Address_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Network_Address_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Network_Address_Cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_Address_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_Address_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_Address_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_Address_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_Address_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_Address_IP_Headline
    ui->Network_Address_IP_Headline = lv_label_create(ui->Network_Address_Cont);
    lv_label_set_text(ui->Network_Address_IP_Headline, "IP address");
    lv_label_set_long_mode(ui->Network_Address_IP_Headline, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Network_Address_IP_Headline, 23, 16);
    lv_obj_set_size(ui->Network_Address_IP_Headline, 180, 14);

    //Write style for Network_Address_IP_Headline, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_Address_IP_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_Address_IP_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Network_Address_IP_Headline, lv_color_hex(0x7e7e7e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Network_Address_IP_Headline, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Network_Address_IP_Headline, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Network_Address_IP_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Network_Address_IP_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Network_Address_IP_Headline, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_Address_IP_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_Address_IP_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_Address_IP_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_Address_IP_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_Address_IP_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_Address_IP_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_Address_IP_Label
    ui->Network_Address_IP_Label = lv_label_create(ui->Network_Address_Cont);
    lv_label_set_text(ui->Network_Address_IP_Label, "127.0.0.1");
    lv_label_set_long_mode(ui->Network_Address_IP_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Network_Address_IP_Label, 20, 40);
    lv_obj_set_size(ui->Network_Address_IP_Label, 180, 16);

    //Write style for Network_Address_IP_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_Address_IP_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_Address_IP_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Network_Address_IP_Label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Network_Address_IP_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Network_Address_IP_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Network_Address_IP_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Network_Address_IP_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Network_Address_IP_Label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_Address_IP_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_Address_IP_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_Address_IP_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_Address_IP_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_Address_IP_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_Address_IP_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_Address_Line
    ui->Network_Address_Line = lv_line_create(ui->Network_Address_Cont);
    static lv_point_t Network_Address_Line[] = {{0, 0},{180, 0},};
    lv_line_set_points(ui->Network_Address_Line, Network_Address_Line, 2);
    lv_obj_set_pos(ui->Network_Address_Line, 20, 66);
    lv_obj_set_size(ui->Network_Address_Line, 180, 1);

    //Write style for Network_Address_Line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Network_Address_Line, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Network_Address_Line, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Network_Address_Line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Network_Address_Line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_Address_Mac_Headline
    ui->Network_Address_Mac_Headline = lv_label_create(ui->Network_Address_Cont);
    lv_label_set_text(ui->Network_Address_Mac_Headline, "Mac address\n");
    lv_label_set_long_mode(ui->Network_Address_Mac_Headline, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Network_Address_Mac_Headline, 20, 76);
    lv_obj_set_size(ui->Network_Address_Mac_Headline, 180, 14);

    //Write style for Network_Address_Mac_Headline, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_Address_Mac_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_Address_Mac_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Network_Address_Mac_Headline, lv_color_hex(0x7e7e7e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Network_Address_Mac_Headline, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Network_Address_Mac_Headline, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Network_Address_Mac_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Network_Address_Mac_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Network_Address_Mac_Headline, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_Address_Mac_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_Address_Mac_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_Address_Mac_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_Address_Mac_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_Address_Mac_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_Address_Mac_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_Address_Mac_Label
    ui->Network_Address_Mac_Label = lv_label_create(ui->Network_Address_Cont);
    lv_label_set_text(ui->Network_Address_Mac_Label, "00:00:00:00:00:00");
    lv_label_set_long_mode(ui->Network_Address_Mac_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Network_Address_Mac_Label, 20, 100);
    lv_obj_set_size(ui->Network_Address_Mac_Label, 180, 16);

    //Write style for Network_Address_Mac_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_Address_Mac_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_Address_Mac_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_Address_Mac_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_Address_Mac_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_Address_Mac_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_Address_Mac_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_Address_Mac_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_Address_Mac_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Network_Address_Mac_Label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Network_Address_Mac_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Network_Address_Mac_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Network_Address_Mac_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Network_Address_Mac_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Network_Address_Mac_Label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_TailScale_Cont
    ui->Network_TailScale_Cont = lv_obj_create(ui->Network);
    lv_obj_set_pos(ui->Network_TailScale_Cont, 10, 190);
    lv_obj_set_size(ui->Network_TailScale_Cont, 220, 40);
    lv_obj_set_scrollbar_mode(ui->Network_TailScale_Cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(ui->Network_TailScale_Cont, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);

    //Write style for Network_TailScale_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_TailScale_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_TailScale_Cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_TailScale_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Network_TailScale_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Network_TailScale_Cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_TailScale_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_TailScale_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_TailScale_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_TailScale_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_TailScale_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_TailScale_Logo_Img
    ui->Network_TailScale_Logo_Img = lv_img_create(ui->Network_TailScale_Cont);
    lv_img_set_src(ui->Network_TailScale_Logo_Img, &_tailscale_alpha_24x24);
    lv_img_set_pivot(ui->Network_TailScale_Logo_Img, 50,50);
    lv_img_set_angle(ui->Network_TailScale_Logo_Img, 0);
    lv_obj_set_pos(ui->Network_TailScale_Logo_Img, 18, 8);
    lv_obj_set_size(ui->Network_TailScale_Logo_Img, 24, 24);

    //Write style for Network_TailScale_Logo_Img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Network_TailScale_Logo_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Network_TailScale_Logo_Img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_TailScale_Logo_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Network_TailScale_Logo_Img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_TailScale_Label
    ui->Network_TailScale_Label = lv_label_create(ui->Network_TailScale_Cont);
    lv_label_set_text(ui->Network_TailScale_Label, "Disconnected");
    lv_label_set_long_mode(ui->Network_TailScale_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Network_TailScale_Label, 50, 12);
    lv_obj_set_size(ui->Network_TailScale_Label, 150, 13);

    //Write style for Network_TailScale_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_TailScale_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_TailScale_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Network_TailScale_Label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Network_TailScale_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Network_TailScale_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Network_TailScale_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Network_TailScale_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Network_TailScale_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_TailScale_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_TailScale_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_TailScale_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_TailScale_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_TailScale_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_TailScale_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_ZeroTier_Cont
    ui->Network_ZeroTier_Cont = lv_obj_create(ui->Network);
    lv_obj_set_pos(ui->Network_ZeroTier_Cont, 10, 146);
    lv_obj_set_size(ui->Network_ZeroTier_Cont, 220, 40);
    lv_obj_set_scrollbar_mode(ui->Network_ZeroTier_Cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(ui->Network_ZeroTier_Cont, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);

    //Write style for Network_ZeroTier_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_ZeroTier_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_ZeroTier_Cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_ZeroTier_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Network_ZeroTier_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Network_ZeroTier_Cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_ZeroTier_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_ZeroTier_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_ZeroTier_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_ZeroTier_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_ZeroTier_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_ZeroTier_Logo_Img
    ui->Network_ZeroTier_Logo_Img = lv_img_create(ui->Network_ZeroTier_Cont);
    lv_img_set_src(ui->Network_ZeroTier_Logo_Img, &_zerotier_alpha_24x24);
    lv_img_set_pivot(ui->Network_ZeroTier_Logo_Img, 50,50);
    lv_img_set_angle(ui->Network_ZeroTier_Logo_Img, 0);
    lv_obj_set_pos(ui->Network_ZeroTier_Logo_Img, 18, 8);
    lv_obj_set_size(ui->Network_ZeroTier_Logo_Img, 24, 24);

    //Write style for Network_ZeroTier_Logo_Img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Network_ZeroTier_Logo_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Network_ZeroTier_Logo_Img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_ZeroTier_Logo_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Network_ZeroTier_Logo_Img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_ZeroTier_Label
    ui->Network_ZeroTier_Label = lv_label_create(ui->Network_ZeroTier_Cont);
    lv_label_set_text(ui->Network_ZeroTier_Label, "Disconnected");
    lv_label_set_long_mode(ui->Network_ZeroTier_Label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Network_ZeroTier_Label, 50, 12);
    lv_obj_set_size(ui->Network_ZeroTier_Label, 150, 13);

    //Write style for Network_ZeroTier_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_ZeroTier_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_ZeroTier_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Network_ZeroTier_Label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Network_ZeroTier_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Network_ZeroTier_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Network_ZeroTier_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Network_ZeroTier_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Network_ZeroTier_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_ZeroTier_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_ZeroTier_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_ZeroTier_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_ZeroTier_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_ZeroTier_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_ZeroTier_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_No_Network_Cont
    ui->Network_No_Network_Cont = lv_obj_create(ui->Network);
    lv_obj_set_pos(ui->Network_No_Network_Cont, 10, 10);
    lv_obj_set_size(ui->Network_No_Network_Cont, 220, 220);
    lv_obj_set_scrollbar_mode(ui->Network_No_Network_Cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_clear_flag(ui->Network_No_Network_Cont, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);

    //Write style for Network_No_Network_Cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_No_Network_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_No_Network_Cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_No_Network_Cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Network_No_Network_Cont, lv_color_hex(0x101010), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Network_No_Network_Cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_No_Network_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_No_Network_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_No_Network_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_No_Network_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_No_Network_Cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_No_Network_Logo_Img
    ui->Network_No_Network_Logo_Img = lv_img_create(ui->Network_No_Network_Cont);
    lv_img_set_src(ui->Network_No_Network_Logo_Img, &_LOGO_alpha_64x64);
    lv_img_set_pivot(ui->Network_No_Network_Logo_Img, 50,50);
    lv_img_set_angle(ui->Network_No_Network_Logo_Img, 0);
    lv_obj_set_pos(ui->Network_No_Network_Logo_Img, 78, 18);
    lv_obj_set_size(ui->Network_No_Network_Logo_Img, 64, 64);

    //Write style for Network_No_Network_Logo_Img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Network_No_Network_Logo_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Network_No_Network_Logo_Img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_No_Network_Logo_Img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Network_No_Network_Logo_Img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Network_No_Network_Headline
    ui->Network_No_Network_Headline = lv_label_create(ui->Network_No_Network_Cont);
    lv_label_set_text(ui->Network_No_Network_Headline, "No Network");
    lv_label_set_long_mode(ui->Network_No_Network_Headline, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Network_No_Network_Headline, 0, 120);
    lv_obj_set_size(ui->Network_No_Network_Headline, 220, 32);

    //Write style for Network_No_Network_Headline, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Network_No_Network_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Network_No_Network_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Network_No_Network_Headline, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Network_No_Network_Headline, &lv_font_montserratMedium_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Network_No_Network_Headline, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Network_No_Network_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Network_No_Network_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Network_No_Network_Headline, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Network_No_Network_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Network_No_Network_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Network_No_Network_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Network_No_Network_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Network_No_Network_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Network_No_Network_Headline, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Network.
    lv_obj_clear_flag(ui->Network_No_Network_Cont, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->Network_Address_Cont, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->Network_ZeroTier_Cont, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->Network_TailScale_Cont, LV_OBJ_FLAG_HIDDEN);

    //Update current screen layout.
    lv_obj_update_layout(ui->Network);

    //Init events for screen.
    events_init_Network(ui);
}
