//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST_F(TestIsLeap, LeapTestOne) {
  ASSERT_EQ(IsLeap(400), true);
}


TEST_F(TestIsLeap, LeapTestTwo) {
  ASSERT_EQ(IsLeap(100), false);
}


TEST_F(TestIsLeap, LeapTestThree) {
  ASSERT_EQ(IsLeap(4), true);
}

TEST_F(TestIsLeap, LeapTestFour) {
  ASSERT_EQ(IsLeap(1), false);
}