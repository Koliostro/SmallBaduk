cmake_minimum_required(VERSION 3.10)

project(Baduk)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(SOURCES
    src/main.cpp
    src/window_system/window.cpp
    src/sprite_system/sprite_system.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(src)

add_executable(${PROJECT_NAME}  ${SOURCES})

target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image)
