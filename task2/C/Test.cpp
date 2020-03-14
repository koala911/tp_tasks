#include "gtest/gtest.h"
#include "A/index.h"
#include "B/lib.h"

TEST(LibTest, Test1) {
    EXPECT_EQ(25, my_sqr(5));
    EXPECT_EQ(4, my_sqr(2));
    EXPECT_EQ(100, my_sqr(10));
    EXPECT_EQ(0, my_sqr(0));
    EXPECT_EQ(4, my_sqr(-2));
    EXPECT_EQ(100, my_sqr(-10));
}

TEST(IndexTest, Test2) {
    EXPECT_EQ(1, x);
}