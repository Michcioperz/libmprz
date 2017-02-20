//
// Created by michcioperz on 20.02.17.
//

#include <libmprz/math.h>
#include "gtest/gtest.h"

TEST(MathAbsTest, ZeroNo) {
    EXPECT_EQ(0, mprz::abs(0));
}

TEST(MathAbsTest, PositiveNumber) {
    EXPECT_EQ(1, mprz::abs(1));
}

TEST(ToString, PositiveNumber) {
    EXPECT_EQ("150", mprz::to_string(150));
}
