#ifndef KdV_header
#define KdV_header

// common packages
#include <iostream>
#include <xtensor/xarray.hpp>
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"

// Define "vector" here for brevity (using xtensor<double,1>)
using vector = xt::xtensor<double,1>;

// function declarations
void double_print_me(double x);
double time_deriv_RHS(const vector& vec,double space_step_size,int index);


#endif //KdV_header
