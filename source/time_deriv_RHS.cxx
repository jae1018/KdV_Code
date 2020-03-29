#include "KdV.h"

// intentionally returning bad values; just making the skeleton first.

double time_deriv_RHS(const vector& vec,double space_step,int index) {
  std::cout << "[";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec(i) << " ";
  }
  std::cout << "]\n";

  std::cout << "I defined this func to return to a double, so here ya go!"
	    << "\n";
  return vec(index);
  //return float(vec.size());
}


