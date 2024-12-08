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

void Tile::DrawTile(short sizeOfsprite, SDL_Renderer * ren, SDL_Texture * tex, short sizeOnScreen = 64, const double angle = 0) {
    SDL_Rect dst;

    dst.h = sizeOnScreen;
    dst.w = sizeOnScreen;
    dst.x = settings.xPos;
    dst.y = settings.yPos; 

    SDL_Rect src;

    src.h = sizeOfsprite;
    src.w = sizeOfsprite;
    src.x = settings.xOffset;
    src.y = settings.yOffset;

    //SDL_RenderCopy(ren, tex,&src, &dst);
    SDL_RenderCopyEx(ren, tex, &src, &dst, angle, NULL, SDL_FLIP_NONE);
    // Present shoud be present only for debug reason 
    //SDL_RenderPresent(ren);
}

void Tile::ChangePos(short newX, short newY) {
    settings.xPos = newX;
    settings.yPos = newY;
}

// Change the tile to new. If we get -1 we don't change that cord
void Tile::ChangeSprite(short newX, short newY) {
    if (newX != -1) {
        settings.xOffset = newX;
    }
    if (newY != -1) {
        settings.yOffset = newY;
    }
}

// Get offsets of Tile. If coord char is wrong will retuen -1
short Tile::getCoordinates(char coord) {
    if (coord == 'x') {
        return settings.xOffset;
    }
    else if (coord == 'y') {
        return settings.yOffset;
    }
    return -1;
}
