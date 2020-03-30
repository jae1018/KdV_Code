/**
* The main function for the KdV solver code Emily and I are writing. This
* code is repsonsible for stating initial parameters and calling the support
* functions.
*
* Author: James "Andy" Edmond
* Date: March 29, 2020
*/

#include "KdV.h"

int main() {
  
  // Define constants
  const double final_length = 2*PI;
  const double final_time = 0.1;
  int const num_space_points = 11;
  int const num_time_points = 101;
  // also we assume that start time and start length are 0

  // Define step sizes based on constants
  double space_step = final_length / (num_space_points - 1);
  double time_step = final_time / (num_time_points - 1);

  // Start off with trivial wave function
  vector arr = xt::empty<double>({num_space_points});
  double step = 0.1;
  std::cout << "init values are...\n[ ";
  for (int i = 0; i < arr.size(); i++) {
    arr(i) = cos(i * space_step);
    std::cout << arr(i) << " ";
  }
  std::cout << "]\n\n";

  arr = time_integrator(arr,time_step,space_step,final_time);

}
