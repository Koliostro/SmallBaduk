#include <SDL2/SDL.h>

#ifndef WINDOW_H
#define WINDOW_H

class Window {
    protected:
        int size_of_window;
    public:
        Window(int size_of_window);

        SDL_Window* create_window();
        void update_window(SDL_Window* window);
};

#endif
