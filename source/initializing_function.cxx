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
  return cos(x);
}
