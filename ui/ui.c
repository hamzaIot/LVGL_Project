// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
void ui_event_Screen1_Button1(lv_event_t * e);
lv_obj_t * ui_Screen1_Button1;
lv_obj_t * ui_Lb_bnt_text_text;
void ui_event_Btn_Clear(lv_event_t * e);
lv_obj_t * ui_Btn_Clear;
lv_obj_t * ui_Screen1_Slider1;
lv_obj_t * ui_Screen1_Spinner1;
lv_obj_t * ui_Screen1_Arc1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Screen1_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        BtnTextClicked(e);
    }
}
void ui_event_Btn_Clear(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        BtnClearClicked(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button1, 100);
    lv_obj_set_height(ui_Screen1_Button1, 50);
    lv_obj_set_align(ui_Screen1_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Lb_bnt_text_text = lv_label_create(ui_Screen1_Button1);
    lv_obj_set_width(ui_Lb_bnt_text_text, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Lb_bnt_text_text, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Lb_bnt_text_text, LV_ALIGN_CENTER);

    ui_Btn_Clear = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Btn_Clear, 100);
    lv_obj_set_height(ui_Btn_Clear, 50);
    lv_obj_set_x(ui_Btn_Clear, -1);
    lv_obj_set_y(ui_Btn_Clear, 84);
    lv_obj_set_align(ui_Btn_Clear, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Btn_Clear, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Btn_Clear, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Slider1 = lv_slider_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Slider1, 567);
    lv_obj_set_height(ui_Screen1_Slider1, 84);
    lv_obj_set_x(ui_Screen1_Slider1, 15);
    lv_obj_set_y(ui_Screen1_Slider1, -160);
    lv_obj_set_align(ui_Screen1_Slider1, LV_ALIGN_CENTER);

    ui_Screen1_Spinner1 = lv_spinner_create(ui_Screen1, 1000, 90);
    lv_obj_set_width(ui_Screen1_Spinner1, 157);
    lv_obj_set_height(ui_Screen1_Spinner1, 168);
    lv_obj_set_x(ui_Screen1_Spinner1, -276);
    lv_obj_set_y(ui_Screen1_Spinner1, 68);
    lv_obj_set_align(ui_Screen1_Spinner1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Spinner1, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_set_style_arc_color(ui_Screen1_Spinner1, lv_color_hex(0xD710E5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Screen1_Spinner1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Screen1_Spinner1, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_Screen1_Arc1 = lv_arc_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Arc1, 150);
    lv_obj_set_height(ui_Screen1_Arc1, 150);
    lv_obj_set_x(ui_Screen1_Arc1, 193);
    lv_obj_set_y(ui_Screen1_Arc1, 69);
    lv_obj_set_align(ui_Screen1_Arc1, LV_ALIGN_CENTER);
    lv_arc_set_value(ui_Screen1_Arc1, 0);

    lv_obj_set_style_bg_color(ui_Screen1_Arc1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Screen1_Button1, ui_event_Screen1_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Btn_Clear, ui_event_Btn_Clear, LV_EVENT_ALL, NULL);

}
void lv_example_tabview_test(void)
{
    /*Create a Tab view object*/
    lv_obj_t * tabview;
    tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 50);

    /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
    lv_obj_t * tab1 = lv_tabview_add_tab(tabview, "Tab 1");
    lv_obj_t * tab2 = lv_tabview_add_tab(tabview, "Tab 2");
    lv_obj_t * tab3 = lv_tabview_add_tab(tabview, "Tab 3");

    /*Add content to the tabs*/
    lv_obj_t * label = lv_label_create(tab1);
    lv_label_set_text(label, "This the first tab\n\n"
                      "If the content\n"
                      "of a tab\n"
                      "becomes too\n"
                      "longer\n"
                      "than the\n"
                      "container\n"
                      "then it\n"
                      "automatically\n"
                      "becomes\n"
                      "scrollable.\n"
                      "\n"
                      "\n"
                      "\n"
                      "Can you see it?");

    label = lv_label_create(tab2);
    lv_label_set_text(label, "Second tab");











    label = lv_label_create(tab3);
    lv_label_set_text(label, "Third tab");

    lv_obj_scroll_to_view_recursive(label, LV_ANIM_ON);

}
static void event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    LV_UNUSED(obj);
    LV_LOG_USER("Button %d clicked", (int)lv_obj_get_index(obj));
}

void lv_example_win_test(void)
{
    lv_obj_t * win = lv_win_create(lv_scr_act(), 40);
    lv_obj_t * btn;
    btn = lv_win_add_btn(win, LV_SYMBOL_LEFT, 40);
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

    lv_win_add_title(win, "A title");

    btn = lv_win_add_btn(win, LV_SYMBOL_RIGHT, 40);
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

    btn = lv_win_add_btn(win, LV_SYMBOL_CLOSE, 60);
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t * cont = lv_win_get_content(win);  /*Content can be added here*/
    lv_obj_t * label = lv_label_create(cont);
    lv_label_set_text(label, "This is\n"
                      "a pretty\n"
                      "long text\n"
                      "to see how\n"
                      "the window\n"
                      "becomes\n"
                      "scrollable.\n"
                      "\n"
                      "\n"
                      "Some more\n"
                      "text to be\n"
                      "sure it\n"
                      "overflows. :)");


}


void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_example_win_test();
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
    //lv_example_tabview_test();

}
