#include <iostream>
#include <cassert>
#include "libmprz.h"

int main() {
	unsigned long long x = -1;
	x >>= 2;
	long long y = -x;
	std::cout << mprz::to_string(y) << std::endl;
	mprz::ring_a_bell(5);
	assert(mprz::does_it_ring_a_bell('\a') == true);
	assert(mprz::does_it_ring_a_bell('u') || mprz::does_it_ring_a_bell('w') || mprz::does_it_ring_a_bell('u') == false);
	assert(mprz::does_it_ring_a_bell("totally doesn't ring \a bell") == true);
	assert(mprz::does_it_ring_a_bell("completely unlike asie") == false);
}
