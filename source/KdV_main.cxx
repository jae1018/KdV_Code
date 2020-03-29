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
  
  vector arr = xt::empty<double>({5});
  for (int i = 0; i < arr.size(); i++) {
    arr(i) = double(i);
  }

  double step = 0.1;
  for (int i = 0; i < arr.size(); i++) {
    time_deriv_RHS(arr,step,i);
  }
}
