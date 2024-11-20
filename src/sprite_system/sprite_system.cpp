#include "sprite_system.h"

#include <SDL2/SDL_render.h>
#include <iostream>

/* Get sprite file from OS and calculate amount of rows and colums */
SpriteSheet::SpriteSheet(const char * path, short size) {
    image_of_sprite = SDL_LoadBMP(path);

    m_sprite.w = size;
    m_sprite.h = size;
}

SpriteSheet::~SpriteSheet() {
    SDL_FreeSurface(image_of_sprite);
};

void SpriteSheet::draw_selected_sprite(SDL_Surface * window_surface, SDL_Rect * position) {
    // After this i got segmentation fault and I don`t know how fix it
    SDL_BlitSurface(image_of_sprite, &m_sprite, window_surface, position); 
}

// Select one sprite from many sprites on spritesheet
void SpriteSheet::select_sprite(short xOffset, short yOffset) {
    m_sprite.x = xOffset * m_sprite.w;
    m_sprite.y = yOffset * m_sprite.h;
}

// Tile part
// Class for drawing that contains position and sprite of itself
Tile::Tile(const char * path, short size, PositionOfSprite * setting) : SpriteSheet(path, size) {
        position.h = size;
        position.w = size;

        settings.xOffset = setting->xOffset;
        settings.yOffset = setting->yOffset;
        settings.xPos = setting->xPos;
        settings.yPos = setting->yPos;

        position.x = settings.xPos;
        position.y = settings.yPos;
}

void Tile::drawTile(SDL_Surface * window_surface) {
    SpriteSheet::select_sprite(settings.xOffset, settings.yOffset);
    SpriteSheet::draw_selected_sprite(window_surface, &position);
}
