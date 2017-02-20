//
// Created by michcioperz on 20.02.17.
//

#include <mprz/math.h>
#include <mprz/bell_utils.h>
#include <gtest/gtest.h>

TEST(MathAbs, Zero) {
    EXPECT_EQ(0, mprz::abs(0));
}

TEST(MathAbs, PositiveNumber) {
    EXPECT_EQ(1, mprz::abs(1));
}

TEST(MathAbs, NegativeNumber) {
    EXPECT_EQ(134, mprz::abs(-134));
}

TEST(ToString, PositiveNumber) {
    EXPECT_EQ("150", mprz::to_string(150));
}

TEST(ToString, NegativeNumber) {
    EXPECT_EQ("-1337", mprz::to_string(-1337));
}

TEST(ToString, Zero) {
    EXPECT_EQ("0", mprz::to_string(0));
}

TEST(DoesItRingABell, ObviousChar) {
    EXPECT_EQ(true, mprz::does_it_ring_a_bell('\a'));
}

TEST(DoesItRingABell, Uwubuntu) {
    EXPECT_EQ(false, mprz::does_it_ring_a_bell("uwubuntu"));
}

TEST(DoesItRingABell, LoudAsie) {
    EXPECT_EQ(true, mprz::does_it_ring_a_bell("\asie\asie\asie\asie\asie\asie"));
}