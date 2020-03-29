/**
* When solving the KdV equation, one needs to isolate the time derivative.
* This moves all other terms of the equation to the right-hand-side (RHS),
* which this function solves for if given the array of values, the spatial
* step size, and the currently considered index.
*
* Author: James "Andy" Edmond
* Date: March 29, 2020
*/

#include "KdV.h"

double time_deriv_RHS(const vector& vec,double space_step,int index) {
  std::cout << "[";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec(i) << " ";
  }
  std::cout << "]\n";

  // define where to get indices based on if we have to "loop around" or not
  int size = vec.size();
  int index_plus_1 = (index + 1) % size;
  int index_plus_2 = (index + 2) % size;
  // also, c++ doesn't perform modulo operation right for negative numbers..
  // gotta do that manually :(
  int index_minus_1 = (index - 1);
  if ( index_minus_1 < 0 ) { index_minus_1 = size - 1; }
  int index_minus_2 = (index - 2);
  if ( index_minus_2 < 0 ) { index_minus_2 = size - abs(index_minus_2); }

  /**std::cout << "For index " << index << " for array of size "
            << vec.size() << " , we get...\n";
  std::cout << "index + 1 = " << index_plus_1 << "\n";
  std::cout << "index + 2 = " << index_plus_2 << "\n";
  std::cout << "index - 1 = " << index_minus_1 << "\n";
  std::cout << "index - 2 = " << index_minus_2 << "\n";*/

  // define the spatial derivative terms
  double third_deriv_term = (  vec(index_plus_2)
		- 2 * ( vec(index_plus_1) - vec(index_minus_1) )
		- vec(index_minus_2)  )
			/  ( 2 * pow(space_step,3) );
  double first_deriv_term = ( vec(index_plus_1) - vec(index_minus_1) )
			        /  ( 2 * space_step );
  double rhs = -1 * third_deriv_term + 6 * vec(index) * first_deriv_term;

  return rhs;
}


