#include "../window_system/window.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#ifndef TILE_H
#define TILE_H

struct PositionOfSprite {
    short xPos;
    short yPos;
    short xOffset;
    short yOffset;
};

class Tile {
    private:
        PositionOfSprite settings;

    public:
        Tile(short size, PositionOfSprite * settings, SDL_Renderer * renderer);

        void DrawTile(short sizeOfsprite, SDL_Renderer * ren, SDL_Texture * tex, short sizeOnScreen, const double angle);
        void ChangePos(short newX, short newY);
        void ChangeSprite(short newX, short newY);
        short getCoordinates(char coord);
};
#endif
