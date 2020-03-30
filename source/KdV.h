/**
* The header file for the KdV solver. Observe that the term vector is used
* here to act as a substitue for xtensor<double,1>!
*
* Author: James "Andy" Edmond
* Date: March 29, 2020
*/

#ifndef KdV_header
#define KdV_header

// common packages
#include <iostream>
#include <xtensor/xarray.hpp>
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include <cmath>

// Define constants
#define PI 3.14159265

// Define "vector" here for brevity (using xtensor<double,1>)
using vector = xt::xtensor<double,1>;

// function declarations
double time_deriv_RHS(double u_i_minus_2,double u_i_minus_1,double u_i,
		      double u_i_plus_1,double u_i_plus_2,double space_step);
vector time_integrator(const vector& vec,double time_step, double space_step,
		       double final_time);
int index_looper(int index, int vec_size);

#endif //KdV_header
