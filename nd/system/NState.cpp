
#include "NState.h"

void NState::create() {
    this->created = true;
}

void NState::update(float dt) {
    // Nothing to do
}

void NState::render() {
    NGroup<NBasic>::render();
}
