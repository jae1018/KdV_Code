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

// Define "vector" here for brevity (using xtensor<double,1>)
using vector = xt::xtensor<double,1>;

// function declarations
double time_deriv_RHS(const vector& vec,double space_step_size,int index);


#endif //KdV_header
