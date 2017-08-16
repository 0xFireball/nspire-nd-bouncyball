
#include "NGroup.h"

template <class T>
NTypedGroup<T>::NTypedGroup(int maxSize) {
    this->maxSize = maxSize;
}

template <class T>
T NTypedGroup<T>::add(T obj) {
    this->members.push_back(obj);
    return obj;
}

template <class T>
T NTypedGroup<T>::remove(T obj) {
    this->members.erase(std::remove(this->members.begin(), this->members.end(), obj),
        this->members.end());
    return obj;
}
