#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#include <vector>
#include <iostream>
#include <SDL2/SDL_render.h>

#ifndef MAIN_H
#define MAIN_H

class Main {
    protected:
        SDL_Window* window;
        SDL_Surface* plane;
    public:
        Main();
        ~Main();

        void Init();
};
#endif
