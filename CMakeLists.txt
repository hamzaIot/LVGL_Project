cmake_minimum_required(VERSION 3.10)
project(lvgl_fb)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(TARGET_CONFIG
TARGET_RPI
#LOCAL_SDL
)

if(${TARGET_CONFIG} STREQUAL LOCAL_SDL)
	message("CMAKE for SDL")
	list(APPEND FLAG USE_SDL_FLAG_FROM_CMAKE_LIST)

	find_package(SDL2 REQUIRED SDL2)
	include_directories(
    	    ${SDL2_INCLUDE_DIRS}
        	${SDL2_INCLUDE_DIRS}/../
        	${PROJECT_SOURCE_DIR}
	)
	
	list(APPEND LIBS lvgl lvgl::examples lvgl::demos lvgl::drivers ${SDL2_LIBRARIES})
endif()


include_directories(.)
add_subdirectory(lvgl)
add_subdirectory(lv_drivers)

set(CMAKE_BUILD_TYPE Debug)

if(${TARGET_CONFIG} STREQUAL TARGET_RPI)
	message("CMAKE for RPI")
	list(APPEND FLAG RPI)

	#which compilers to use for C and C++
	set(CMAKE_C_COMPILER   arm-linux-gnueabihf-gcc)
	set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

	#where is the target environment located
	set(CMAKE_FIND_ROOT_PATH  "/usr/bin")

	list(APPEND LIBS lvgl lvgl::examples lvgl::demos lvgl::drivers)
	
endif()



file(GLOB_RECURSE INCLUDES "lv_drivers/*.h" "ui/ui.h" "ui/ui_helpers.h" "lvgl/*.h" "./*.h" "print_pierre.h") # ${INCLUDES}
file(GLOB_RECURSE SOURCES  "lv_drivers/*.c" "ui/ui.c" "ui/ui.helpers.c" "lvgl/*.c" "ui/ui_events.cpp" "print_pierre.cpp") # ${SOURCES}


add_executable(${PROJECT_NAME} main.cpp ${INCLUDES}  ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${FLAG})






