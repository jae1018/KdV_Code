#include <gtest/gtest.h>
#include <assert.h>
#include "KdV.h"

/**
* Testing for the KdV_initializer function. Separately checks to see if the
* number of elements created and the values of those elements are correct.
* Element testing is done presuming that initializing_function.cxx is
* already accurate!!
*
* Made operational / reformatted from: Emily's KdV_initializer testing code
* author: James "Andy" Edmond
* date: April 6, 2020
*/

// Tests to see if the *number* of elements is correct
TEST(KdV_Testing,Correct_Num_Elements) {

  int num_elems = 11;
  double final_length = 3.0;
  vector self_made = xt::empty<double>({num_elems});
  vector func_made = KdV_initializer(num_elems,final_length);
  EXPECT_EQ(self_made.size(),func_made.size());

}

// Tests to see if the elements are correct
TEST(KdV_Testing,All_Elems_Corect) {

  double error = 0.001;
  int num_elems = 11;
  double final_length = 3.14159;
  double step_size = final_length / (num_elems - 1);
  // prep custom init vector
  vector self_made = xt::empty<double>({num_elems});
  for (int i = 0; i < num_elems; i++) {
    self_made(i) = initializing_function(step_size * i);
  }
  // compare to function-made vector
  vector func_made = KdV_initializer(num_elems,final_length);
  for (int i = 0; i < num_elems; i++) {
    EXPECT_TRUE(abs(func_made(i) - self_made(i)) < error);
  }

}
