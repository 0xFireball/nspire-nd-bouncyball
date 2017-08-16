
#pragma once

#include "../deps.h"

class NBasic {
private:
    bool _exists = true;
public:
    virtual void update(float dt) = 0;
    virtual void render() = 0;
    
    void destroy() {
        this->_exists = false;
    }

    void initialize() {
        this->_exists = true;
    }
};
