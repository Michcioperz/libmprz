//
// Created by michcioperz on 20.02.17.
//

#include "math.h"
#include "stack.h"

namespace mprz {
    template<typename T>
    T abs(T value) {
        if (value < 0)
            return -value;
        return value;
    }
    template<typename T>
    std::string to_string(T value) {
        if (value == 0) return "0";
        bool sign = value < 0;
        stack<char> digits;
        do {
            digits.push(abs(value % 10) + 48);
            value /= 10;
        } while (value != 0);
        if (sign) digits.push('-');
        std::string ret = "";
        do {
            ret += digits.top();
            digits.pop();
        } while (!digits.empty());
        return ret;
    }
}