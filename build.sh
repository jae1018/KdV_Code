# Run me build files!

# Remake everything
cd build
cmake ../
make

# Execute main program and tests
echo "The KdV code took this long to complete.."
time ./main_exec
#./test_time_deriv_RHS
#./test_index_looper

#rm -rf *
