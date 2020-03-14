#include "gtest/gtest.h"
#include "A/index.h"
#include "B/lib.h"

TEST(LibTest, Test1) {
    EXPECT_EQ(25, sqr(5));
    EXPECT_EQ(4, sqr(2));
    EXPECT_EQ(100, sqr(10));
    EXPECT_EQ(0, sqr(0));
    EXPECT_EQ(4, sqr(-2));
    EXPECT_EQ(100, sqr(-10));
}

TEST(IndexTest, Test2) {
    EXPECT_EQ(1, x);
}