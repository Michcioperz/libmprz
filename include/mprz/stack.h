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
        struct element {
            element *parent;
            T value;
        };
        element *__top = nullptr;
    public:
        bool empty() {
            return __top == nullptr;
        }

        size_t count() {
            element *ptr = __top;
            size_t counter = 0;
            while (ptr != nullptr) {
                counter++;
                ptr = ptr->parent;
            }
        }

        T top() {
            return __top->value;
        }

        void push(T value) {
            element *new_top = new element();
            new_top->parent = __top;
            new_top->value = value;
            __top = new_top;
        }

        void pop() {
            element *old_top = __top;
            __top = old_top->parent;
            delete old_top;
        }
    };
}

#endif //LIBMPRZ_STACK_H
