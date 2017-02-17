#include <string>
#include <stack>

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
}
