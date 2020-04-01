/**
* The driver for the KdV solver code Emily and I are writing. This
* code is responsible for stating initial parameters and calling the support
* functions.
*
* Author: James "Andy" Edmond
* Date: March 29, 2020
*/

#include "KdV.h"

int main() {

  // Define constants
  const char* filename_out = "KdV_data.txt";
  const double final_length = 2*PI;
  const double final_time = 3.0;
  int const num_space_points = 51;
  int const num_time_points = 300001;
  // also we assume that start time and start length are 0

  // Define step sizes based on constants
  double space_step = final_length / (num_space_points - 1);
  double time_step = final_time / (num_time_points - 1);

  // prepare init data according to KdV_initializer
  vector init_vec = KdV_initializer(num_space_points,final_length);

  // evolve KdV
  time_evolver(init_vec,time_step,space_step,final_time,filename_out);
}
