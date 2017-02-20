//
// Created by michcioperz on 20.02.17.
//

#include <cstdio>
#include "bell_utils.h"

namespace mprz {
    void ring_a_bell() {
        std::putchar('\a');
    }

    void ring_a_bell(size_t count) {
        while (count--) {
            ring_a_bell();
        }
    }

    bool does_it_ring_a_bell(char ch) {
        return ch == '\a';
    }

    bool does_it_ring_a_bell(std::string str) {
        for (char ch : str) {
            if (does_it_ring_a_bell(ch)) return true;
        }
        return false;
    }
}