# KdV_Code
Runs a Korteweg-de Vries simulation in C++.
Parameters to modify are in KdV_main.cxx (located in source).
The code begins to break when using > 60 spatial grid points so use caution.

# Execution
To execute, run the build sheel script using ./build.sh.
The output data is saved as KdV_data.txt within build (which should be imported
to a local computer for plotting using our Python program).
