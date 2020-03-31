/**
* Computes the time evolution of the KdV equation by computing its time derivative.
* The new array computed at each step and printed to an output file and this data
* is later plotted as a function of time and space.
*
* Author: James "Andy" Edmond
* Date: March 31, 2020
*/

#include "KdV.h"

void time_evolver(const vector& init_vec, double time_step,
			double space_step, double final_time, const char *out_file)
{
  int size = init_vec.size();
  vector next_vec = xt::empty<double>({size});
  vector prev_vec = xt::empty<double>({size});
  int num_iters = ceil(final_time/time_step);

  // initialize prev_vec for loop
  for (int i = 0; i < size; i++) {
    prev_vec(i) = init_vec(i);
  }

  // This loops tracks over time
  for (int i = 0; i < num_iters; i++) {

    // while this loop tracks over the spatial grid; completing this loop
    // means that one time step can be completed.
    for (int a = 0; a < size; a++) {
      //double rhs = time_deriv_RHS(init_vec,space_step,a);
      // Found a helpful link; check it later in more detail
//https://math.stackexchange.com/questions/1341074/runge-kutta-method-for-pde
// Shiiiiiiiiittt... time_deriv_RHS has to be rewritten... :( b/c there's no
// way it can know when to use increment values in k1 through k4 i.e. when
// we need to consider u_i
// for now, just treat time_deriv_RHS as though it accepts 6 inputs:
//   u_i-2 through u_i+2 and space_step_size

      // determine u_i_minus_2 through u_i_plus_2
      double u_i_minus_2 = prev_vec(index_looper(a-2,size));
      double u_i_minus_1 = prev_vec(index_looper(a-1,size));
      double u_i = prev_vec(index_looper(a,size));
      double u_i_plus_1 = prev_vec(index_looper(a+1,size));
      double u_i_plus_2 = prev_vec(index_looper(a+2,size));

    /** if ( abs(u_i - 1) < 0.001 ) {
       std::cout << "u_i-2 = " << u_i_minus_2 << "\n"
                 << "u_i-1 = " << u_i_minus_1 << "\n"
                 << "u_i = " << u_i << "\n"
                 << "u_i+1 = " << u_i_plus_1 << "\n"
                 << "u_i+2 = " << u_i_plus_2 << "\n"; }*/

      // determine k1
      double k1 = time_deriv_RHS(u_i_minus_2,u_i_minus_1,u_i,
			u_i_plus_1,u_i_plus_2,space_step);

      // determine k2
      double k2 = time_deriv_RHS(u_i_minus_2 + k1/2,
			u_i_minus_1 + k1/2, u_i + k1/2,
			u_i_plus_1 + k1/2, u_i_plus_2 + k1/2,space_step);

      // determine k3
      double k3 = time_deriv_RHS(u_i_minus_2 + k2/2,
			u_i_minus_1 + k2/2, u_i + k2/2,
			u_i_plus_1 + k2/2, u_i_plus_2 + k2/2,space_step);

      // determine k4
      double k4 = time_deriv_RHS(u_i_minus_2 + k3,
			u_i_minus_1 + k3, u_i + k3,
			u_i_plus_1 + k3, u_i_plus_2 + k3,space_step);
      /**if (a == 0)
        { std::cout << "k1 = " << k1 << "\n"
                  << "k2 = " << k2 << "\n"
                  << "k3 = " << k3 << "\n"
                  << "k4 = " << k4 << "\n"; }*/
      next_vec(a) = prev_vec(a) + (time_step/6)*(k1 + 2*(k2 + k3) + k4);

    }
    prev_vec = next_vec;
    // printing contents
    std::cout << "at t = " << 0 + i*time_step << "...\n[ ";
    for (int q = 0; q < size; q++) {
      std::cout << prev_vec(q) << " ";
    }
    std::cout << "]\n\n";

  }

 // return next_vec;
}
