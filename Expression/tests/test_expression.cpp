#include <gtest/gtest.h>
#include "../include/expression.h"  // Replace with the actual file name

using namespace oop;
// Test for Constant class
TEST(ConstantTest, EvaluateConstant) {
    Constant c(5.0);
    EXPECT_DOUBLE_EQ(c.evaluate(), 5.0);
    EXPECT_EQ(c.toString(), "5.000000");  // std::to_string produces 6 digits by default
}

TEST(ConstantTest, NegativeConstant) {
    Constant c(-3.5);
    EXPECT_DOUBLE_EQ(c.evaluate(), -3.5);
    EXPECT_EQ(c.toString(), "-3.500000");
}

// Test for BinaryPlus class
TEST(BinaryPlusTest, SimpleAddition) {
    Constant left(4.0);
    Constant right(2.5);
    BinaryPlus sum(left, right);

    EXPECT_DOUBLE_EQ(sum.evaluate(), 6.5);
    EXPECT_EQ(sum.toString(), "(4.000000 + 2.500000)");
}

TEST(BinaryPlusTest, NestedAddition) {
    Constant c1(1.0);
    Constant c2(2.0);
    Constant c3(3.0);
    BinaryPlus sum1(c1, c2);
    BinaryPlus sum2(sum1, c3);

    EXPECT_DOUBLE_EQ(sum2.evaluate(), 6.0);
    EXPECT_EQ(sum2.toString(), "((1.000000 + 2.000000) + 3.000000)");
}


