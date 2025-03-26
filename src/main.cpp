#include "main.h"
#include "window_system/window.h"
#include "sprite_system/sprite_system.h"
#include <cmath>

#define SIZE_ON_SCREEN 64
#define SIZE_OF_SPRITE 16
#define SIZE_OF_SCREEN 600

#define SIZE_OF_BOARD 8

#define SDL_MAIN_HANDLED

constexpr short offset() {
    return (SIZE_OF_SCREEN - SIZE_ON_SCREEN * SIZE_OF_BOARD) >> 1;
}

#ifdef Windows
    // Here we make platform dependent code
    #include <Windows.h>
#endif

//Now we rotate throught all states of tile. Later we need to create way
//to determine what color of stone need to place. 
//
//For this we for sure need a turn system. But the main goal now is
//creating algorithm for geterming conditions for removing stones.
void checkClick(SDL_MouseButtonEvent &b, std::vector<std::vector<Tile>> &tiles) {
    if (b.button == SDL_BUTTON_LEFT) {
        short xIndex, yIndex;

        xIndex = std::floor(b.x / SIZE_ON_SCREEN) - 1;
        yIndex = std::floor(b.y / SIZE_ON_SCREEN) - 1;
        
        if (tiles[yIndex][xIndex].getCoordinates('y') == 2 * SIZE_OF_SPRITE) {
            tiles[yIndex][xIndex].ChangeSprite(-1, 0);
        }
        else {
            tiles[yIndex][xIndex].ChangeSprite(-1, tiles[yIndex][xIndex].getCoordinates('y') + SIZE_OF_SPRITE);
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);


    #ifdef Windows
        HWND windowHandle = GetConsoleWindow();
        ShowWindow(windowHandle, SW_HIDE);
    #endif

    Window screen(SIZE_OF_SCREEN);

    SDL_Window* window = screen.create_window();
    
    /*
     * I'm not really know what is going here. But here were alocate 
     * objects for board otherwise it will crash
    */ 
    std::vector<std::vector<PositionOfSprite>> VisualTiles (SIZE_OF_BOARD, std::vector<PositionOfSprite>(SIZE_OF_BOARD, PositionOfSprite()));

    std::vector<std::vector<Tile>> tiles;

    /* -------*/
    SDL_Renderer * ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);

    SDL_Surface * load = IMG_Load("images/test.png");
    SDL_Texture * tex = SDL_CreateTextureFromSurface(ren, load);
    SDL_FreeSurface(load);
    /*-------*/

    for (char i = 0; i <= SIZE_OF_BOARD - 1; i++) {
        for (char j = 0; j <= SIZE_OF_BOARD - 1; j++) {

            if (i == 0 || i == SIZE_OF_BOARD - 1) {
                switch (j) {
                    case 0: 
                        VisualTiles[i][j].xPos = j * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].yPos = i * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].xOffset = SIZE_OF_SPRITE;
                        VisualTiles[i][j].yOffset = 0;
                        break;
                    case SIZE_OF_BOARD - 1: 
                        VisualTiles[i][j].xPos = j * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].yPos = i * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].xOffset = SIZE_OF_SPRITE;
                        VisualTiles[i][j].yOffset = 0;
                        break;
                    default:
                        VisualTiles[i][j].xPos = j * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].yPos = i * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].xOffset = 2 * SIZE_OF_SPRITE;
                        VisualTiles[i][j].yOffset = 0;
                        break;
                }
            }
            else {
                switch (j) {
                    case 0: 
                        VisualTiles[i][j].xPos = j * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].yPos = i * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].xOffset = 2 * SIZE_OF_SPRITE;
                        VisualTiles[i][j].yOffset = 0;
                        break;
                    case SIZE_OF_BOARD - 1: 
                        VisualTiles[i][j].xPos = j * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].yPos = i * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].xOffset = 2 * SIZE_OF_SPRITE;
                        VisualTiles[i][j].yOffset = 0;
                        break;
                    default:
                        VisualTiles[i][j].xPos = j * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].yPos = i * SIZE_ON_SCREEN + offset();
                        VisualTiles[i][j].xOffset = 0;
                        VisualTiles[i][j].yOffset = 0;
                        break;
                }
            }
        }
    }
    /*
     * Here we can't prealocate sizes because
     * we create a vector of class objects
     */
    
    for (char i = 0; i <= SIZE_OF_BOARD - 1; i++) {
        std::vector<Tile> Temp;
        for (char j = 0; j <= SIZE_OF_BOARD - 1; j++) {
            Temp.push_back(Tile(SIZE_OF_SPRITE, &VisualTiles[i][j], ren));
        }
        tiles.push_back(Temp);
    }

    bool running = true;

    Uint64 frameStart, frameTime;

    Uint64 frameDelay = 17;
    
    // main loop
    while (running) {
        
        frameStart = SDL_GetTicks64();

        SDL_RenderClear(ren);
    // Function to set right angle and display it.
    // ============================================
    // The first time it run for all blocks
    // but later it will run only once per turn
    // for update reasons
        double angle;
        for (char i = 0; i <= SIZE_OF_BOARD - 1; i++) {
            for (char j = 0; j <= SIZE_OF_BOARD - 1; j++) {

                switch (i) {
                    case 0:
                        switch (j) {
                            case SIZE_OF_BOARD - 1:
                                angle = 90;
                                break;
                            default:
                                angle = 0;
                                break;
                        }
                        break;
                    case SIZE_OF_BOARD - 1:
                        switch(j) {
                            case 0:
                                angle = 270;
                                break;
                            default:
                                angle = 180;
                                break;
                        }
                        break;
                    default:
                        switch(j) {
                            case 0:
                                angle = -90;
                                break;
                            case SIZE_OF_BOARD - 1:
                                angle = 90;
                                break;
                        }
                        break;
                }

                //======================================================

                tiles[i][j].DrawTile(SIZE_OF_SPRITE, ren, tex, SIZE_ON_SCREEN, angle);
                angle = 0;
            }
        }

        SDL_RenderPresent(ren);
        SDL_Event event;
        
        //event loop
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    checkClick(event.button, tiles);
                    break;
            }
        }

        frameTime = SDL_GetTicks64() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
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
