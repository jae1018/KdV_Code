#ifndef  Emily_KdV  
#define  Emily_KdV
#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include <cmath>

using vector =xt::xtensor<double,1>;


//declarations

double initializing_function (double x);

vector KdV_initializer (int num_points, double end_length);

#endif//Emily_Kdv
