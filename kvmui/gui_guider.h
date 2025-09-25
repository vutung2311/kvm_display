/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef struct
{
  
	lv_obj_t *Main;
	bool Main_del;
	lv_obj_t *Main_Logo_Img;
	lv_obj_t *Main_Clock_Label;
	lv_obj_t *Main_Date_Label;
	lv_obj_t *Main_HDMI_Cont;
	lv_obj_t *Main_HDMI_Img;
	lv_obj_t *Main_HDMI_Headline;
	lv_obj_t *Main_USB_Cont;
	lv_obj_t *Main_USB_Img;
	lv_obj_t *Main_USB_Headline;
	lv_obj_t *Monitor;
	bool Monitor_del;
	lv_obj_t *Monitor_CPU_Used_Cont;
	lv_obj_t *Monitor_CPU_Used_Headline;
	lv_obj_t *Monitor_CPU_Used_Arc;
	lv_obj_t *Monitor_CPU_Used_Label;
	lv_obj_t *Monitor_RAM_Used_Cont;
	lv_obj_t *Monitor_RAM_Used_Headline;
	lv_obj_t *Monitor_RAM_Used_Arc;
	lv_obj_t *Monitor_RAM_Used_Label;
	lv_obj_t *Monitor_CPU_Temp_Cont;
	lv_obj_t *Monitor_CPU_Temp_Headline;
	lv_obj_t *Monitor_CPU_Temp_Label;
	lv_obj_t *Monitor_Net_Cont;
	lv_obj_t *Monitor_Net_Img;
	lv_obj_t *Monitor_Net_Up_Img;
	lv_obj_t *Monitor_Net_Up_Label;
	lv_obj_t *Monitor_Net_Down_Img;
	lv_obj_t *Monitor_Net_Down_Label;
	lv_obj_t *Network;
	bool Network_del;
	lv_obj_t *Network_Address_Cont;
	lv_obj_t *Network_Address_IP_Headline;
	lv_obj_t *Network_Address_IP_Label;
	lv_obj_t *Network_Address_Line;
	lv_obj_t *Network_Address_Mac_Headline;
	lv_obj_t *Network_Address_Mac_Label;
	lv_obj_t *Network_TailScale_Cont;
	lv_obj_t *Network_TailScale_Logo_Img;
	lv_obj_t *Network_TailScale_Label;
	lv_obj_t *Network_ZeroTier_Cont;
	lv_obj_t *Network_ZeroTier_Logo_Img;
	lv_obj_t *Network_ZeroTier_Label;
	lv_obj_t *Network_No_Network_Cont;
	lv_obj_t *Network_No_Network_Logo_Img;
	lv_obj_t *Network_No_Network_Headline;
	lv_obj_t *Version;
	bool Version_del;
	lv_obj_t *Version_ui_Version_cont;
	lv_obj_t *Version_Logo_Img;
	lv_obj_t *Version_Hostname_Headline;
	lv_obj_t *Version_Hostname_Label;
	lv_obj_t *Version_Line;
	lv_obj_t *Version_App_Version_Headline;
	lv_obj_t *Version_App_Version_Label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_Main(lv_ui *ui);
void setup_scr_Monitor(lv_ui *ui);
void setup_scr_Network(lv_ui *ui);
void setup_scr_Version(lv_ui *ui);
LV_IMG_DECLARE(_LOGO_alpha_64x64);
LV_IMG_DECLARE(_HDMI_alpha_64x64);
LV_IMG_DECLARE(_USB_alpha_64x64);
LV_IMG_DECLARE(_net_alpha_64x64);
LV_IMG_DECLARE(_up_alpha_20x20);
LV_IMG_DECLARE(_up_alpha_20x20);
LV_IMG_DECLARE(_tailscale_alpha_24x24);
LV_IMG_DECLARE(_zerotier_alpha_24x24);
LV_IMG_DECLARE(_LOGO_alpha_64x64);
LV_IMG_DECLARE(_LOGO_alpha_64x64);

LV_FONT_DECLARE(lv_font_Abel_regular_48)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_48)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_32)


#ifdef __cplusplus
}
#endif
#endif
