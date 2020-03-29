#include "KdV.h"

int main() {
  
  vector arr = xt::empty<double>({5});
  for (int i = 0; i < arr.size(); i++) {
    arr(i) = float(i);
  }

  double step = 0.1;
  for (int i = 0; i < arr.size(); i++) {
    time_deriv_RHS(arr,step,i);
  }
}
