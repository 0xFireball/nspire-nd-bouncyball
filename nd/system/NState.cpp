
#include "NState.h"

void NState::create() {
    this->created = true;
}

void NState::update(float) {
    // Nothing to do, subclass should override
}

void NState::render(SDL_Surface *surface) {
    NGroup<NBasic>::render(surface);
}

void NState::setClearColor(NColor col) {
    this->_clearColor = col;
}
