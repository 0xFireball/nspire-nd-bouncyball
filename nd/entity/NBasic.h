
#pragma once

#include "../deps.h"

class NBasic {
public:
    bool _exists = true;

    virtual void update(float dt) {}
    virtual void render() {}
    
    void destroy() {
        this->_exists = false;
    }

    void initialize() {
        this->_exists = true;
    }

    virtual ~NBasic() {}
};
