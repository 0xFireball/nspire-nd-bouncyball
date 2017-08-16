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
    this->_clock = new NClock();
}

void NGame::switch_state(NState* state) {
    if (this->_currentState != nullptr) delete this->_currentState;
    this->_currentState = state;
}

void NGame::init_vars() {
    this->_frameCount = 0;
}

void NGame::destroy() {
    // delete the current state
    this->switch_state(nullptr);

    // free SDL surface
    SDL_FreeSurface(this->_screen);

    // free other resources
    if (this->_clock != nullptr) delete this->_clock;
}

void NGame::exit() {
    this->destroy();
    SDL_Quit();
}

void NGame::start() {
    this->_clock->reset();
    this->game_loop();
}

void NGame::game_loop() {
    while (!this->_quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    this->_quit = true;
            }
        }
        // loop frame
        this->update();
        this->render();

        this->_frameCount++;
    }
}

void NGame::update() {
    this->_clock->update();
    int dt = this->_clock->getElapsed();
    // update the current state
    this->_currentState->update(dt / 1000.0f);
}

void NGame::render() {
    // render the current state
    this->_currentState->render();
}

#ifdef desktop
// Desktop-specific
#endif
