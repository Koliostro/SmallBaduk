#include "main.h"
#include "window_system/window.h"
#include "sprite_system/sprite_system.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

int main() {

    SDL_Init(SDL_INIT_EVERYTHING);
    
    Window screen(600);

    SDL_Window* window = screen.create_window();
    SDL_Surface* plane = screen.create_surface(window);

    std::vector<PositionOfSprite> VisualTiles;

    for (short i = 0; i <= 3; i++) {
        VisualTiles.push_back(PositionOfSprite());
        
        VisualTiles[i].xPos = i * 64;
        VisualTiles[i].xOffset = i * 64;
        VisualTiles[i].yOffset = 0;
        VisualTiles[i].yPos = 0;
    }

    Tile blocks[1] = {Tile("../images/test.bmp", 64, &VisualTiles[0])};

    bool running = true;
    
    // main loop
    while (running) {
        SDL_Event event;

        SDL_Rect srcrect = {0, 0, 64, 64};
        SDL_Rect dstrect = {0, 0, 64, 64}; 

        //event loop
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        blocks[0].drawTile(plane);
        SDL_UpdateWindowSurface(window);
        
    }

// Thouse statments should be in deconstructor
    
    SDL_DestroyWindow(window);

    window = NULL;
    plane = NULL;

    SDL_Quit();
    IMG_Quit();

    return 0;
}
