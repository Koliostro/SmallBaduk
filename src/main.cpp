#include "main.h"
#include "window_system/window.h"
#include "sprite_system/sprite_system.h"

#include <SDL2/SDL_error.h>

int main() {

    SDL_Init(SDL_INIT_EVERYTHING);
    
    Window screen(600);

    SDL_Window* window = screen.create_window();
    //SDL_Surface* plane = screen.create_surface(window);

    std::vector<PositionOfSprite> VisualTiles;
    std::vector<Tile> tiles;

    VisualTiles.push_back(PositionOfSprite());

    for (short i = 0; i <= 2; i++) {
        VisualTiles[i].xPos = i * 64;
        VisualTiles[i].xOffset = i * 64;
        VisualTiles[i].yOffset = 0;
        VisualTiles[i].yPos = 0;
    }

    /* -------*/
    SDL_Renderer * ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

    SDL_Surface * load = SDL_LoadBMP("../images/test.bmp");
    SDL_Texture * tex = SDL_CreateTextureFromSurface(ren, load);
    SDL_FreeSurface(load);
    /*-------*/

    for (short i = 0; i <= 2; i++) {
        tiles.push_back(Tile(64, &VisualTiles[i], ren));
    }
   
    bool running = true;

    
    // main loop
    while (running) {
        SDL_Event event;

        for (short i = 0; i <= 2; i++) {
            tiles[i].DrawTile(64, ren, tex);
        }

        //event loop
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        
    }

// Thouse statments should be in deconstructor
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(tex);

    window = NULL;
    //plane = NULL;

    SDL_Quit();
    IMG_Quit();

    return 0;
}
