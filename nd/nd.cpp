#include "nd.h"

NGame::NGame() {}

void NGame::init(int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);
    if (width == 0) width = DISPLAY_WIDTH;
    if (height == 0) height = DISPLAY_HEIGHT;
    this->_screen = SDL_SetVideoMode(width, height, DISPLAY_BPP, SDL_SWSURFACE);
}

#ifdef desktop
// Desktop-specific
#endif
