#include <string>
#include <cstdio>

namespace mprz {
	template<typename T>
	class stack {
		protected:
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
				size_t ret = 0;
				element *elem = __top;
				while (elem != nullptr) {
					ret++;
					elem = elem->parent;
				}
				return ret;
			}
			T top() {
				if (empty()) {
					// UNDEFINED BEHAVIOUR
					// YOU ASKED FOR IT
					int x = 1 / 0;
					return x;
				}
				return __top->value;
			}
			void push(T item) {
				element *elem = new element();
				elem->parent = __top;
				elem->value = item;
				__top = elem;
			}
			void pop() {
				element *elem = __top;
				__top = elem->parent;
				delete elem;
			}
	};
	template<typename T>
	T abs(T t) {
		if (t < 0) return -t;
		return t;
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
