#include <string>
#include <stack>
#include <cstdio>

namespace mprz {
	template<typename T>
	T abs(T t) {
		if (t < 0) return -t;
		return t;
	}
	template<typename T>
	std::string to_string(T value) {
		if (value == 0) return "0";
		bool sign = value < 0;
		std::stack<char> digits;
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
	template <typename T>
	void ring_a_bell(T count) {
		for (T i = 0; i < count; i++) std::putchar('\a');
	}
	void ring_a_bell() {
		ring_a_bell(1);
	}
	bool does_it_ring_a_bell(char ch) {
		if (ch == '\a') return true;
		return false;
	}
	bool does_it_ring_a_bell(std::string str) {
		for (size_t i = 0; i < str.size(); i++) {
			if (does_it_ring_a_bell(str[i])) return true;
		}
		return false;
	}
}
