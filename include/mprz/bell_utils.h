//
// Created by michcioperz on 20.02.17.
//

#ifndef LIBMPRZ_BELL_UTILS_H
#define LIBMPRZ_BELL_UTILS_H

#include <cstddef>
#include <string>

namespace mprz {
    void ring_a_bell();

    void ring_a_bell(size_t count);

    bool does_it_ring_a_bell(char ch);

    bool does_it_ring_a_bell(std::string str);
}


#endif //LIBMPRZ_BELL_UTILS_H
