
#pragma once

#include "../deps.h"

#include "../group/NGroup.h"

class NState : public NTypedGroup<NBasic> {
public:
    bool created = false;

    NState() : NTypedGroup(0) {}

    virtual void create();
    virtual void update(float dt);
    virtual void render();

    virtual ~NState() {}
};
