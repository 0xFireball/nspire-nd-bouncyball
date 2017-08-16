#include "NGame.h"

NGame::NGame() {}

void NGame::platform_init(int argc, char** argv) {
    if (argc > 0) {
        char* program = argv[0];
        std::string cwd = program;
        cwd = cwd.substr(0, cwd.find_last_of('/') + 1);
        this->_cwd = cwd;
    }
}

void NGame::init(int width, int height, int targetFramerate) {
    SDL_Init(SDL_INIT_VIDEO);
    if (width == 0) width = DISPLAY_WIDTH;
    if (height == 0) height = DISPLAY_HEIGHT;
    this->_screen = SDL_SetVideoMode(width, height, DISPLAY_BPP, SDL_SWSURFACE);

    this->_targetFramerate = targetFramerate;

    // initialize
    this->init_vars();

    // prepare rendering loop
    this->_clock = std::unique_ptr<NClock>(new NClock());
}

void NGame::switch_state(NState* state) {
    
}

void NGame::init_vars() {
    this->_frameCount = 0;
}

void NGame::destroy() {
    SDL_FreeSurface(this->_screen);
}

void NGame::exit() {
    this->destroy();
    SDL_Quit();
}

void NGame::start() {
    this->_clock.reset();
    this->game_loop();
}

void NGame::game_loop() {
    
}

void NGame::update(int elapsed) {

}

void NGame::render() {

}

#ifdef desktop
// Desktop-specific
#endif
