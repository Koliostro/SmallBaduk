#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#include <vector>
#include <iostream>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_error.h>

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
