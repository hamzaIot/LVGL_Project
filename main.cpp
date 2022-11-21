#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include "print_pierre.h"
#include "ui/ui.h"

#ifdef USE_SDL_FLAG_FROM_CMAKE_LIST
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lv_drivers/sdl/sdl.h"
#endif


#define DISP_BUF_SIZE (128 * 1024)


#ifdef RPI

static void hal_init(void);


static void hal_init(void)
{

	 /*Linux frame buffer device init*/
	    fbdev_init();

	    /*A small buffer for LittlevGL to draw the screen's content*/
	    static lv_color_t buf[DISP_BUF_SIZE];

	    /*Initialize a descriptor for the buffer*/
	    static lv_disp_draw_buf_t disp_buf;
	    lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);

	    /*Initialize and register a display driver*/
	    static lv_disp_drv_t disp_drv;
	    lv_disp_drv_init(&disp_drv);
	    disp_drv.draw_buf   = &disp_buf;
	    disp_drv.flush_cb   = fbdev_flush;
	    disp_drv.hor_res    = 720;
	    disp_drv.ver_res    = 720;
	    lv_disp_drv_register(&disp_drv);

	    evdev_init();
	    static lv_indev_drv_t indev_drv_1;
	    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
	    indev_drv_1.type = LV_INDEV_TYPE_POINTER;

	    /*This function will be called periodically (by the library) to get the mouse position and state*/
	    indev_drv_1.read_cb = evdev_read;
	    lv_indev_drv_register(&indev_drv_1);

	    /*Create a Demo*/
	    //lv_demo_widgets();


}

#endif


#ifdef USE_SDL_FLAG_FROM_CMAKE_LIST
static void hal_init2(void);

static void hal_init2(void)
{
   /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
    sdl_init();

   /*Create a display buffer*/
    static lv_color_t buf[SDL_HOR_RES * SDL_VER_RES];
    static lv_disp_draw_buf_t disp_draw_buf;
    lv_disp_draw_buf_init(&disp_draw_buf, buf, NULL, SDL_HOR_RES * SDL_VER_RES);

   /*Create a display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv); /*Basic initialization*/
    disp_drv.draw_buf = &disp_draw_buf;
    disp_drv.flush_cb = sdl_display_flush;
   disp_drv.hor_res = SDL_HOR_RES;
    disp_drv.ver_res = SDL_VER_RES;
    lv_disp_drv_register(&disp_drv);

    /* Add a mouse as input device */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv); /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = sdl_mouse_read;
   lv_indev_drv_register(&indev_drv);
}
#endif




/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}

void hal_init_general(){
#ifdef RPI
	hal_init();
#endif

#ifdef USE_SDL_FLAG_FROM_CMAKE_LIST
	hal_init2();
#endif

}


int main(void)
{
    /*LittlevGL init*/
    lv_init();


    hal_init_general();


    ui_init();

    //print_pierre();

    /*Handle LitlevGL tasks (tickless mode)*/
    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}

