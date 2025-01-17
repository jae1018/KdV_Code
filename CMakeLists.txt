
cmake_minimum_required (VERSION 3.11)

project(KdV_Andy)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP)

# If we knew GoogleTest is installed, we can just use the following single line
find_package(GTest)

# but if not, we'll fetch it ourselves
if (NOT GTEST_FOUND)
  include(FetchContent)
  FetchContent_Declare(googletest
    GIT_REPOSITORY    https://github.com/google/googletest.git
    GIT_TAG           release-1.8.0
    )
  #FetchContent_MakeAvailable(googletest)
  FetchContent_GetProperties(googletest)
  if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()
  
  add_library(GTest::GTest INTERFACE IMPORTED)
  target_include_directories(GTest::GTest INTERFACE "${googletest_SOURCE_DIR}/googletest/include")
  target_link_libraries(GTest::GTest INTERFACE gtest)
  
  add_library(GTest::Main INTERFACE IMPORTED)
  target_link_libraries(GTest::Main INTERFACE gtest_main)
endif()

find_package(xtl QUIET)
if (NOT xtl_FOUND)
  include(FetchContent)
  FetchContent_Declare(xtl
    GIT_REPOSITORY    https://github.com/xtensor-stack/xtl.git
    )
  #FetchContent_MakeAvailable(xtl)
  FetchContent_GetProperties(xtl)
  if (NOT xtl_POPULATED)
    FetchContent_Populate(xtl)
    add_subdirectory(${xtl_SOURCE_DIR} ${xtl_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()
endif()
  
find_package(xtensor QUIET)
if (NOT xtensor_FOUND)
  include(FetchContent)
  FetchContent_Declare(xtensor
    GIT_REPOSITORY    https://github.com/xtensor-stack/xtensor.git
    )
  #FetchContent_MakeAvailable(xtensor)
  FetchContent_GetProperties(xtensor)
  if (NOT xtensor_POPULATED)
    FetchContent_Populate(xtensor)
    add_subdirectory(${xtensor_SOURCE_DIR} ${xtensor_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()
endif()
  

# -- Create general KdV library --
add_library(KdV_lib 
source/time_deriv_RHS.cxx source/time_evolver.cxx
source/index_looper.cxx source/initializing_function.cxx
source/KdV_initializer.cxx)
target_link_libraries(KdV_lib xtensor)

# -- Compile main program --
add_executable(main_exec source/KdV_main.cxx)
target_link_libraries(main_exec KdV_lib)
if (OpenMP_CXX_FOUND)
  target_link_libraries(main_exec OpenMP::OpenMP_CXX)
endif()

# -- Adding in some testing --
# Time_deriv_RHS
add_executable(test_time_deriv_RHS source/test_time_deriv_RHS.cxx)
target_link_libraries(test_time_deriv_RHS KdV_lib GTest::GTest GTest::Main)

# index_looper
add_executable(test_index_looper source/test_index_looper.cxx)
target_link_libraries(test_index_looper KdV_lib GTest::GTest GTest::Main)

# KdV initializer
add_executable(test_KdV_init source/test_KdV_initializer.cxx)
target_link_libraries(test_KdV_init KdV_lib GTest::GTest GTest::Main)
