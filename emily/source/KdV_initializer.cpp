#include "Emily_KdV.h"

vector KdV_initializer (int num_points, double end_length)
{

    vector init_vec =xt::empty<double>({num_points});
    double step_size=(end_length/(num_points -1));
    for (int i=0; i<num_points; i++)
	{
		init_vec(i)=initializing_function(step_size*i);
	}
    return init_vec;
}
//tests
TEST(KdV, initial values)
{
  std::<int> num_points =1, <double> end_length = 1;
  EXPECT_EQ(init_vec(i), {1.0});
}

