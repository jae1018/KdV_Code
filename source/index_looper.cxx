#include "KdV.h"

/**
* Handles indices when "index" is >= the vector size or is < 0. Since we
* have periodic boundary conditions (and hence, index 0 is equivalent to
* index N - 1 for a vector of size N), the idea is to interpret index -1 as
* index (N - 1) - 1 (and so on for subsequent negative numbers) or index
* N as index 1.
*
* Author: James "Andy" Edmond
* Date: March 30, 2020
*/

int index_looper(int index,int vec_size) {
  int return_index = index;
  int last_index = vec_size - 1;
  if (index >= vec_size) { return_index = index % last_index; }
  if (index < 0) { return_index = last_index + index; }
  return return_index;
}
