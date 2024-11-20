#include "sprite_system.h"

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>

#include <iostream>

// Tile part
// Class for drawing that contains position and sprite of itself
Tile::Tile(short size, PositionOfSprite * setting, SDL_Renderer * renderer) {
    
    settings.xOffset = setting->xOffset;
    settings.yOffset = setting->yOffset;
    settings.xPos = setting->xPos;
    settings.yPos = setting->yPos;

}

void Tile::DrawTile(short sizeOfsprite, SDL_Renderer * ren, SDL_Texture * tex) {
    SDL_Rect dst;

    dst.h = sizeOfsprite;
    dst.w = sizeOfsprite;
    dst.x = settings.xPos;
    dst.y = settings.yPos; 

    SDL_Rect src;

    src.h = sizeOfsprite;
    src.w = sizeOfsprite;
    src.x = settings.xOffset;
    src.y = settings.yOffset;

    SDL_RenderCopy(ren, tex,&src, &dst);
    SDL_RenderPresent(ren);
}

void Tile::ChangePos(short newX, short newY) {
    settings.xPos = newX;
    settings.yPos = newY;
}

void Tile::ChangeSprite(short newX, short newY) {
    settings.xOffset = newX;
    settings.yOffset = newY;
}
