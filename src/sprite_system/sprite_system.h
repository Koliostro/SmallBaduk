#include "../window_system/window.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#ifndef SPRITEWORK_H
#define SPRITEWORK_H

class SpriteSheet {
    private:
        SDL_Rect m_sprite;
        SDL_Surface *image_of_sprite;

    public:
        SpriteSheet(const char * path, short size);
        ~SpriteSheet();

        void select_sprite(short x, short y);
        void draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *pos);
};  
#endif

#ifndef TILE_H
#define TILE_H

struct PositionOfSprite {
    short xPos;
    short yPos;
    short xOffset;
    short yOffset;
};

class Tile : public SpriteSheet {
    private:
        PositionOfSprite settings;
        SDL_Rect position;

    public:
        Tile(const char * path, short size, PositionOfSprite * setting);
        void drawTile(SDL_Surface * window_surface);
};
#endif
