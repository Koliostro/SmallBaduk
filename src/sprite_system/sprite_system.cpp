#include "sprite_system.h"

/* Get sprite file from OS and calculate amount of rows and colums */
SpriteSheet::SpriteSheet(const char * path, short rows, short colms) {
    image_of_sprite = SDL_LoadBMP(path);

    m_sprite.w = image_of_sprite->w / colms;
    m_sprite.h = image_of_sprite->h / rows;
    
}

SpriteSheet::~SpriteSheet() {
    SDL_FreeSurface(image_of_sprite);
};

void SpriteSheet::draw_selected_sprite(SDL_Surface * window_surface, SDL_Rect * position) {
    SDL_BlitSurface(image_of_sprite, &m_sprite, window_surface, position);
}

// Select one sprite from many sprites on spritesheet
void SpriteSheet::select_sprite(short xOffset, short yOffset) {
    m_sprite.x = xOffset * m_sprite.w;
    m_sprite.y = yOffset * m_sprite.h;
}

// Tile part
// Class for drawing that contains position and sprite of itself
Tile::Tile(const char * path, short * pos, short size, short * offset, short rows, short colms) : SpriteSheet(path, rows, colms) {
        position.h = size;
        position.w = size;

        position.x = *pos;
        position.y = *(pos + 1); 

        xOffset = *offset;
        yOffset = *(offset + 1);
}

void Tile::drawTile(SDL_Surface * window_surface) {
    SpriteSheet::select_sprite(xOffset, yOffset);
    SpriteSheet::draw_selected_sprite(window_surface, &position);
}
