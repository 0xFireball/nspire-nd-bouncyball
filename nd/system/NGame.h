
#pragma once

#include "../deps.h"
#include "NState.h"

class NGame {
  private:
    SDL_Surface *_screen;
    int _targetFramerate;
    std::string _cwd;

  public:
    NGame();
    void platform_init(int argc, char** argv);
    void init(int width, int height, int targetFramerate);
    void switch_state(NState* state);

#ifdef desktop
// desktop specific
#endif
};
