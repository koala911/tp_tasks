//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST_F(LeapTestCase, LeapTestOne) {
  ASSERT_EQ(IsLeap(400), true);
}


TEST_F(LeapTestCase, LeapTestTwo) {
  ASSERT_EQ(IsLeap(100), false);
}


TEST_F(LeapTestCase, LeapTestThree) {
  ASSERT_EQ(IsLeap(4), true);
}

TEST_F(LeapTestCase, LeapTestFour) {
  ASSERT_EQ(IsLeap(1), false);
}

TEST_F(LeapTestCase, LeapTestFive) {
  ASSERT_THROW(IsLeap(-1), std::invalid_argument);
}
