
#pragma once

#include "../deps.h"

class NClock {
private:
    int _last;
    int _dt;
public:
    NClock() {
        this->reset();
    }

    int getElapsed() {
        return _dt;
    }

    void update() {
        int now = SDL_GetTicks();
        _dt = now - _last;
        _last = now;
    }

    void reset() {
        _last = SDL_GetTicks();
    }
};
