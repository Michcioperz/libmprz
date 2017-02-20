//
// Created by michcioperz on 20.02.17.
//

#ifndef LIBMPRZ_STACK_H
#define LIBMPRZ_STACK_H

#include <cstddef>

namespace mprz {
    template<typename T>
    class stack {
    private:
        struct element;
        element *__top = nullptr;
    public:
        bool empty();

        size_t count();

        T top();

        void push(T value);

        void pop();
    };
}

#endif //LIBMPRZ_STACK_H
