
#pragma once

#include "../deps.h"

#include "../group/NGroup.h"

class NState : public NGroup<NBasic> {
public:
    bool created = false;

    NState() : NGroup(0) {}

    virtual void create();
    virtual void update(float dt);
    virtual void render();

    virtual ~NState() {}
};
