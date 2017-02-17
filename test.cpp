#include <iostream>
#include "libmprz.h"

int main() {
	unsigned long long x = -1;
	x >>= 2;
	long long y = -x;
	std::cout << mprz::to_string(y) << std::endl;
}
