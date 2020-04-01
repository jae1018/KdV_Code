/**
* When solving the KdV equation, one needs to isolate the time derivative.
* This moves all other terms of the equation to the right-hand-side (RHS),
* which this function solves for if given adjacent values of the considered
* index and the spatial step size.
*
* Author: James "Andy" Edmond
* Date: March 29, 2020
*/

#include "KdV.h"

double time_deriv_RHS(double u_i_minus_2, double u_i_minus_1, double u_i,
		      double u_i_plus_1, double u_i_plus_2,double space_step)
{
  // define the spatial derivative terms
  double third_deriv_term = (  u_i_plus_2
		- 2 * ( u_i_plus_1 - u_i_minus_1 )
		- u_i_minus_2  )
			/  ( 2 * pow(space_step,3) );
  double first_deriv_term = ( u_i_plus_1 - u_i_minus_1 )
			        /  ( 2 * space_step );
  double rhs = -1 * third_deriv_term - 6 * u_i * first_deriv_term;  //made last neg
  return rhs;
}


