
#include "NGroup.h"

template <class T>
NGroup<T>::NGroup(int maxSize) {
    this->maxSize = maxSize;
}

template <class T>
T NGroup<T>::add(T obj) {
    this->members.push_back(obj);
    return obj;
}

template <class T>
T NGroup<T>::remove(T obj) {
    this->members.erase(std::remove(this->members.begin(), this->members.end(), obj),
        this->members.end());
    return obj;
}

template <class T>
void NGroup<T>::render() {
    for (T& member: this->members) {
        if (member != nullptr && member->exists) {
            member->render();
        }
    }
}
