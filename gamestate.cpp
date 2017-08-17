#include "gamestate.h"

void GameState::create() {
    // add sprite
    // TODO

    this->setClearColor(NColor(84, 84, 84));

    NState::create();
}

void GameState::update(float dt) {
    NState::update(dt);
}
