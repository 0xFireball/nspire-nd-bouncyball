
#pragma once

#include "../deps.h"

#include "../entity/NBasic.h"

template <class T>
class NGroup : public NBasic {
private:
    int _freePosition = 0;

public:
    std::vector<T> members;
    int memberCount = 0;
    int maxSize = 0;

    NGroup(int maxSize);
    T add(T obj);
    T remove(T obj);
    virtual void render();
    
    virtual ~NGroup() {}
};
