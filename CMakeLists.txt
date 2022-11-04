cmake_minimum_required(VERSION 2.6)

project(lvgl_fb)



include_directories(.)
add_subdirectory(lvgl)
add_subdirectory(lv_drivers)

set(CMAKE_BUILD_TYPE Debug)

#which compilers to use for C and C++
set(CMAKE_C_COMPILER   arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)


#
#where is the target environment located
set(CMAKE_FIND_ROOT_PATH  "/usr/bin")



file(GLOB_RECURSE INCLUDES "lv_drivers/*.h" "ui/ui.h" "ui/ui_helpers.h" "lvgl/*.h" "./*.h" "print_pierre.h") # ${INCLUDES}
file(GLOB_RECURSE SOURCES  "lv_drivers/*.c" "ui/ui.c" "ui/ui.helpers.c" "lvgl/*.c" "ui/ui_events.cpp" "print_pierre.cpp") # ${SOURCES}


#sdl
#find_package(SDL2 REQUIRED SDL2)
#include_directories(
#        ${SDL2_INCLUDE_DIRS}
#        ${SDL2_INCLUDE_DIRS}/../
#        ${PROJECT_SOURCE_DIR}
#)




add_executable(${PROJECT_NAME} main.cpp ${INCLUDES}  ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE lvgl lvgl::examples lvgl::demos lvgl::drivers)
