#include "window.h"

Window::Window(int size) {
    size_of_window = size;
}

SDL_Window* Window::create_window() {
    SDL_Window* window = SDL_CreateWindow("Baduk", 
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
            this->size_of_window, this->size_of_window, SDL_WINDOW_SHOWN);

    return window;
}

void update_window(SDL_Window* window) {
    SDL_UpdateWindowSurface(window);
}
