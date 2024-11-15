#include "../window_system/window.h"

#include <SDL2/SDL_image.h>

#ifndef SPRITEWORK_H
#define SPRITEWORK_H

class SpriteSheet {
    private:
        SDL_Rect m_sprite;
        SDL_Surface *image_of_sprite;

    public:
        SpriteSheet(const char * path, short rows, short colms);
        ~SpriteSheet();

        void select_sprite(short x, short y);
        void draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *pos);
};  
#endif

#ifndef TILE_H
#define TILE_H

class Tile : public SpriteSheet {
    private:
        short xOffset;
        short yOffset;

    public:
        SDL_Rect position;
        Tile(const char * path, short * pos, short size, short * offset, short rows, short colms);
        void drawTile(SDL_Surface * window_surface);
};
#endif
