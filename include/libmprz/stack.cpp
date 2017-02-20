//
// Created by michcioperz on 20.02.17.
//

#include "stack.h"

template<typename T>
struct mprz::stack<T>::element {
    element *parent;
    T value;
};

template <typename T>
bool mprz::stack<T>::empty() {
    return __top == nullptr;
}

template <typename T>
size_t mprz::stack<T>::count() {
    element *ptr = __top;
    size_t counter = 0;
    while (ptr != nullptr) {
        counter++;
        ptr = ptr->parent;
    }
}

template<typename T>
T mprz::stack<T>::top() {
    return __top->value;
}

template<typename T>
void mprz::stack<T>::push(T value) {
    element* new_top = new element();
    new_top->parent = __top;
    new_top->value = value;
    __top = new_top;
}

template <typename T>
void mprz::stack<T>::pop() {
    element* old_top = __top;
    __top = old_top->parent;
    delete old_top;
}
