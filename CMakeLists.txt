cmake_minimum_required(VERSION 3.10)

project(Baduk)

#Need to change flags to needed
set(Debug_option "-Wall;-g")
set(Release_option "")
set(Small_option "")

set(Release_option_link "Wl, --gc-sections, --fwhole-program, -s, --build-id=none")
set(Small_option_link "-Wl, --gc-sections")

set(CMAKE_CONFIGURATION_TYPES "Release;Debug;Small")
set(CMAKE_DEFAULT_BUILD_TYPE "Debug")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(SOURCES
    src/main.cpp
    src/window_system/window.cpp
    src/sprite_system/sprite_system.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(src)

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_options(
    ${PROJECT_NAME}
    PUBLIC
    "$<$<CONFIG:Debug>:${Debug_option}>")

target_compile_options(
    ${PROJECT_NAME}
    PUBLIC
    "$<$<CONFIG:Release>:${Release_option}>")

target_compile_options(
    ${PROJECT_NAME}
    PUBLIC
    "$<$<CONFIG:Small>:${Small_option}>")

target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image)

target_link_options(
    ${PROJECT_NAME}
    PUBLIC
    "$<$<CONFIG:Release>:${Release_option_link}>")

target_link_options(
    ${PROJECT_NAME}
    PUBLIC
    "$<$<CONFIG:Small>:${Small_option_link}>")
