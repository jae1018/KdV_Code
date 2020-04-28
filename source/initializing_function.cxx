/**
* This function defines the initial value of the KdV solver. It's to be
* be called by the initializer for the entire code.
*
* Reformatted from: Emily's "initializing_function.cpp"
* Author: James "Andy" Edmond
* March 31, 2020
*/

#include "KdV.h"

double initializing_function(double x) {
  //return cos(x);
  double width = 0.05;
  double amp = 1/sqrt(2*3.14159265*width);
  double shift = x - 3.14159265;
  return amp * exp(-pow(shift,2)/(2*width));
}
