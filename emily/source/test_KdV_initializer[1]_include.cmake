if(EXISTS "/home/eom1002/KdV_Code/emily/source/test_KdV_initializer[1]_tests.cmake")
  include("/home/eom1002/KdV_Code/emily/source/test_KdV_initializer[1]_tests.cmake")
else()
  add_test(test_KdV_initializer_NOT_BUILT test_KdV_initializer_NOT_BUILT)
endif()
