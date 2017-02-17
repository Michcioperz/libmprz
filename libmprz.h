#include <string>
#include <stack>
#include <cmath>

namespace mprz {
	std::string to_string(long long value) {
		if (value == 0) return "0";
		bool sign = value < 0;
		std::stack<char> digits;
		do {
			digits.push(std::abs(value % 10) + 48);
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
