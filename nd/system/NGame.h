
#pragma once

#include "../deps.h"
#include "NState.h"
#include "NClock.h"

class NGame {
  private:
    SDL_Surface *_screen;
    int _targetFramerate;
    std::string _cwd;
    int _frameCount;
    std::unique_ptr<NClock> _clock;

    void init_vars();

  protected:
    void destroy();
    void game_loop();
    void update(int elapsed);
    void render();

  public:
    NGame();
    void platform_init(int argc, char** argv);
    void init(int width, int height, int targetFramerate);
    void switch_state(NState* state);
    void start();
    void exit();

#ifdef desktop
// desktop specific
#endif
};
