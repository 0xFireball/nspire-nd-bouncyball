
#include "NState.h"

void NState::create() {
    this->created = true;
}

void NState::update(float) {
    // Nothing to do, subclass should override
}

void NState::render() {
    NGroup<NBasic>::render();
}
