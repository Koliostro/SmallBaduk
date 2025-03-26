cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Release)

set(CXX_STANDART 11)
set(CXX_STANDART_REQUIRED ON)

set(Name Baduk)

set(SOURCES
    src/main.cpp
    src/window_system/window.cpp
    src/sprite_system/sprite_system.cpp
)

if (isDebug)
    add_compile_options(-Wall -Wextra -Wpedantic -ggdb)
endif()

project(${Name} CXX)

add_executable(${Name} ${SOURCES})

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    # $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    SDL2::SDL2main
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

if (WIN32)
    add_definitions(-DSDL_MAIN_HANDELED)
    #add_link_options(-mwindows)
    
    target_compile_definitions(${Name}
    PUBLIC
      $<$<CONFIG:Debug>:OE_DEBUG>
      $<$<CONFIG:RelWithDebInfo>:OE_DEBUG>
      $<$<CONFIG:Release>:OE_RELEASE>
      $<$<CONFIG:MinSizeRel>:OE_RELEASE>
)    
endif()