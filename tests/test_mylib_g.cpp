#include <gtest/gtest.h>
#include "mylib.h"

TEST(AddTest, BasicAddition) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
}

TEST(DivTest, ValidDivision) {
    int result;
    EXPECT_EQ(mydiv(10, 2, &result), DIV_SUCCESS);
    EXPECT_EQ(result, 5);
}

TEST(DivTest, DivisionByZero) {
    int result;
    EXPECT_EQ(mydiv(10, 0, &result), DIV_ERR_DIV_BY_ZERO);
}

TEST(DivTest, NullPointer) {
    EXPECT_EQ(mydiv(10, 2, nullptr), DIV_ERR_NULL_PTR);
}
