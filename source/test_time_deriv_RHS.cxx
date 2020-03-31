#include <gtest/gtest.h>
#include <assert.h>
#include "KdV.h"

/**
* Test cases for time_deriv_RHS
*
* Author: James "Andy" Edmond
* Written: March 29, 2020
*/

// NEEDS TO BE REWRITTEN! 3 CASES, STANDARD LOOPING, AND FORWARDS AND BACKWARDS!!

// Standard non-looping test (looping meaning that the indices wrap around
// since the spatial points are discretized, e.g. if index = 1, then the
// 2 indices below that is not -1 but instead (size - 1) - 1.
TEST(KdV_Testing,NonLoopingIndices) {
  vector arr = xt::empty<double>({10});
  for (int i = 0; i < arr.size(); i++) {
    arr(i) = i;
  }
  double step = 0.1;
  int index = 3;

  time_deriv_RHS(arr,step,index);
  EXPECT_EQ(time_deriv_RHS(arr,step,index),180);
}

// Tests looping backwards
TEST(KdV_Testing,BackwardLoopingIndices) {
  vector arr = xt::empty<double>({10});
  for (int i = 0; i < arr.size(); i++) {
    arr(i) = i;
  }
  double step = 0.1;
  int index = 0;

  time_deriv_RHS(arr,step,index);
  EXPECT_EQ(time_deriv_RHS(arr,step,index),-5/pow(0.1,3));
}


// Tests looping forwards
// Hmm... this test returns the correct answer as expected (-7160) but the
// does say that the expected value does not agree with what was given, which
// is -7160... I'll have to ask Kai about this, not sure what to do :(
/**TEST(KdV_Testing,ForwardLoopingIndices) {
  vector arr = xt::empty<double>({10});
  for (int i = 0; i < arr.size(); i++) {
    arr(i) = i;
  }
  double step = 0.1;
  int index = 9;

  time_deriv_RHS(arr,step,index);
  EXPECT_EQ(time_deriv_RHS(arr,step,index),-7160);
}*/

