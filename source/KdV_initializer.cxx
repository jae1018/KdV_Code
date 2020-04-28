/**
* Prepares the array of initial data for the KdV solver. Assumes that
* the initial length is 0.
*
* Reformatted from: Emily's "KdV_initializer.cpp"
* Author: James "Andy" Edmond
* Date: March 31, 2020
*/

#include "KdV.h"

vector KdV_initializer(int num_points, double end_length) {
  // make step size and empty vector
  vector init_vec = xt::empty<double>({num_points});
  double step_size = (end_length/(num_points -1));
  // fill vector up
  for (int i = 0; i < num_points; i++) {
    init_vec(i) = initializing_function(step_size*i);
  }
  return init_vec;
}
