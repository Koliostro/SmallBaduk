#include <SDL.h>

#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_error.h>
#include <SDL_mouse.h>
#include <SDL_timer.h>

#include <SDL_image.h>

#include <vector>
#include <iostream>

#ifdef __GNUC__
    #define Linux
#else
    #define Windows
#endif

#ifndef MAIN_H
#define MAIN_H

class Main {
    protected:
        SDL_Window* window;
    public:
        Main();
        ~Main();

        void Init();
};
#endif
