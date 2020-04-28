#include <gtest/gtest.h>
#include <assert.h>
#include "KdV.h"

/**
* Test cases for time_deriv_RHS. Incorporating the index looper function,
* 3 test cases here will involve a "standard" calculation (i.e. involves no
* looping around the indices), backwards looping, and forwards looping.
*
* Author: James "Andy" Edmond
* Written: March 29, 2020
*/

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

  double u_i = arr(index);
  double u_i_plus_1 = arr(index+1);
  double u_i_plus_2 = arr(index+2);
  double u_i_minus_1 = arr(index-1);
  double u_i_minus_2 = arr(index-2);

  double result = time_deriv_RHS(u_i_minus_2,u_i_minus_1,u_i,u_i_plus_1,
	u_i_plus_2,step);
  EXPECT_EQ(result,-180);
}

// Backwards looping
TEST(KdV_Testing,BackwardsLooping) {
  vector arr = xt::empty<double>({10});
  for (int i = 0; i < arr.size(); i++) {
    arr(i) = i;
  }
  double step = 0.1;
  int index = 1;

  double u_i = arr(index);
  double u_i_plus_1 = arr(index+1);
  double u_i_plus_2 = arr(index+2);
  double u_i_minus_1 = arr(index-1);
  double u_i_minus_2 = arr(index_looper(index-2,10));

  double result = time_deriv_RHS(u_i_minus_2,u_i_minus_1,u_i,u_i_plus_1,
	u_i_plus_2,step);
  double val = 4440;
  double error = 0.1;
  EXPECT_TRUE(abs(result - val) < error);
}


// Tests looping forwards
// Hmm... this test returns the correct answer as expected (-7160) but the
// does say that the expected value does not agree with what was given, which
// is -7160... I'll have to ask Kai about this, not sure what to do :(
TEST(KdV_Testing,ForwardLoopingIndices) {
  vector arr = xt::empty<double>({10});
  for (int i = 0; i < arr.size(); i++) {
    arr(i) = i;
  }
  double step = 0.1;
  int index = 9;

  double u_i = arr(index);
  double u_i_plus_1 = arr(index_looper(index+1,10));
  double u_i_plus_2 = arr(index_looper(index+2,10));
  double u_i_minus_1 = arr(index-1);
  double u_i_minus_2 = arr(index-2);

  double result = time_deriv_RHS(u_i_minus_2,u_i_minus_1,u_i,u_i_plus_1,
	u_i_plus_2,step);
  double val = -2610;
  double error = 0.1;
  EXPECT_TRUE(abs(result - val) < error);
}

