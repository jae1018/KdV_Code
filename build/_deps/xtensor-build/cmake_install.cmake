# Install script for directory: /home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/xtensor" TYPE FILE FILES
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xaccessible.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xaccumulator.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xadapt.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xarray.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xassign.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xaxis_iterator.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xbroadcast.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xbuffer_adaptor.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xbuilder.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xcomplex.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xcontainer.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xcsv.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xdynamic_view.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xeval.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xexception.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xexpression.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xexpression_holder.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xexpression_traits.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xfixed.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xfunction.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xfunctor_view.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xgenerator.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xhistogram.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xindex_view.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xinfo.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xio.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xiterable.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xiterator.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xjson.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xlayout.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xmanipulation.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xmasked_view.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xmath.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xmime.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xnoalias.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xnorm.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xnpy.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xoffset_view.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xoperation.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xoptional.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xoptional_assembly.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xoptional_assembly_base.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xoptional_assembly_storage.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xpad.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xrandom.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xreducer.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xrepeat.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xscalar.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xsemantic.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xshape.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xslice.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xsort.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xstorage.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xstrided_view.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xstrided_view_base.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xstrides.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xtensor.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xtensor_config.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xtensor_forward.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xtensor_simd.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xutils.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xvectorize.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xview.hpp"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-src/include/xtensor/xview_utils.hpp"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor" TYPE FILE FILES
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-build/xtensorConfig.cmake"
    "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-build/xtensorConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor/xtensorTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor/xtensorTargets.cmake"
         "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-build/CMakeFiles/Export/lib/cmake/xtensor/xtensorTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor/xtensorTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor/xtensorTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor" TYPE FILE FILES "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-build/CMakeFiles/Export/lib/cmake/xtensor/xtensorTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/jae1018/Proj1/KdV_Code/build/_deps/xtensor-build/xtensor.pc")
endif()

