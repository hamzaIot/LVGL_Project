// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

extern lv_obj_t * ui_Screen1;
void ui_event_Screen1_Button1(lv_event_t * e);
extern lv_obj_t * ui_Screen1_Button1;
extern lv_obj_t * ui_Lb_bnt_text_text;
void ui_event_Btn_Clear(lv_event_t * e);
extern lv_obj_t * ui_Btn_Clear;
extern lv_obj_t * ui_Screen1_Slider1;
extern lv_obj_t * ui_Screen1_Spinner1;
extern lv_obj_t * ui_Screen1_Arc1;

void BtnTextClicked(lv_event_t * e);
void BtnClearClicked(lv_event_t * e);






void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
