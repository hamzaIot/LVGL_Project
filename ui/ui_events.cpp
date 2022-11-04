// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#include "ui.h"
#include <iostream>
#include <string>

static int Counter = 0;
void BtnTextClicked(lv_event_t * e)
{
	std::cout << "Hello hamza c'est moi le C++ \n";
	Counter++;
	std::string s = std::to_string(Counter);
	lv_label_set_text(ui_Lb_bnt_text_text, s.c_str());
	// Your code here
}

void BtnClearClicked(lv_event_t * e)
{

	Counter = 0;
	std::string s = std::to_string(Counter);
	lv_label_set_text(ui_Lb_bnt_text_text, s.c_str());

	// Your code here
}



