/**
* Computes the time evolution of the KdV equation by computing its time derivative.
* The new array computed at each step and printed to an output file and this data
* is later plotted as a function of time and space.
*
* Author: James "Andy" Edmond
* Date: March 31, 2020
*/

#include "KdV.h"

void time_evolver(const vector& init_vec, double time_step, double space_step,
		double final_time, const char* out_file)
{
  // --- Prepare initial data ---

  // create arrays and params for time loop
  int size = init_vec.size();
  vector next_vec = xt::empty<double>({size});
  vector prev_vec = xt::empty<double>({size});
  int num_iters = ceil(final_time/time_step);

  // prepare file output
  std::ofstream output_file;
  output_file.open(out_file);
  output_file << "num time points = " << num_iters + 1
              << " and num space points = " << size << "\n";

  // --- Save initial data ---

  // initialize prev_vec for loop
  for (int i = 0; i < size; i++) {
    prev_vec(i) = init_vec(i);
  }

  // print init data to file
  output_file << 0.0 << "\n";
  for (int i = 0; i < size; i++) {
    output_file << init_vec(i) << "  ";
  }
  output_file << "\n";

  // --- Iterate to get subsequent data ---

  // Time loop
  double time = 0.0;
  for (int i = 0; i < num_iters; i++) {
    // Space loop
    #pragma omp parallel for
    for (int a = 0; a < size; a++) {
      // determine u_i_minus_2 through u_i_plus_2
      double u_i_minus_2 = prev_vec(index_looper(a-2,size));
      double u_i_minus_1 = prev_vec(index_looper(a-1,size));
      double u_i = prev_vec(index_looper(a,size));
      double u_i_plus_1 = prev_vec(index_looper(a+1,size));
      double u_i_plus_2 = prev_vec(index_looper(a+2,size));

      // On a special note, the RHS of the time derivative in the KdV
      // equation is *independent* of time! So really, k1=k2=k3=k4.
      double k1 = time_deriv_RHS(u_i_minus_2,u_i_minus_1,u_i,
			u_i_plus_1,u_i_plus_2,space_step);
      /**double k2 = time_deriv_RHS(u_i_minus_2,
			u_i_minus_1, u_i,
			u_i_plus_1, u_i_plus_2,space_step);
      double k3 = time_deriv_RHS(u_i_minus_2,
			u_i_minus_1, u_i,
			u_i_plus_1, u_i_plus_2,space_step);
      double k4 = time_deriv_RHS(u_i_minus_2,
			u_i_minus_1, u_i,
			u_i_plus_1, u_i_plus_2,space_step);*/
      double k2 = k1;
      double k3 = k1;
      double k4 = k1;
      next_vec(a) = prev_vec(a) + (time_step/6)*(k1 + 2*(k2 + k3) + k4);
    }    // end space loop (and parallelization)

    // prepare vars for next iter
    prev_vec = next_vec;
    time = (i + 1) * time_step;

    // print data to file
    output_file << time << "\n";
    for (int i = 0; i < size; i++) {
      output_file << next_vec(i) << "  ";
    }
    output_file << "\n";

  }   // end time loop

  // close file, end function
  output_file.close();
}
