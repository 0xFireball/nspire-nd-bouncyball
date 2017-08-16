
#pragma once

#include "../deps.h"

class NBasic {
private:
    bool _exists = true;
public:
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
