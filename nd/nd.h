#include "platform.h"

// Other
#include <string>

// SDL
#include <SDL/SDL.h>
#include <SDL/SDL_config.h>

class NGame {
  private:
    SDL_Surface *_screen;

  public:
    NGame();
    void init();

#ifdef desktop
// desktop specific
#endif
};
