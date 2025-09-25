#ifndef SCREEN_H
#define SCREEN_H

#include "lvgl/lvgl.h"
#include "kvmui/gui_guider.h"

lv_ui guider_ui;

void init_lvgl();
void *run_lvgl_loop(void *arg);
void ui_set_text(const char *name, const char *text);
void ui_set_network();
void ui_set_no_network();
lv_obj_t *ui_get_obj(const char *name);
lv_img_dsc_t *ui_get_image(const char *name);

#endif // SCREEN_H
