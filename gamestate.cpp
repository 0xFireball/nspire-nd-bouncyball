#include "gamestate.h"

void GameState::create() {
    // add sprite
    // TODO

    this->setClearColor(NColor(84, 84, 84));

    NSprite* ball = new NSprite(20, 20);
    ball->loadGraphic("ball.bmp.tns");
    this->add(ball);

    NState::create();
}

void GameState::update(float dt) {
    // TODO: add custom update logic
    NState::update(dt);
}
