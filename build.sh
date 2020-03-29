# Run me build files!

# Remake everything
cd build
cmake ../
make

# Execute main program and tests
./main_exec
./test_time_deriv_RHS

#rm -rf *
