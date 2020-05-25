cmake_minimum_required(VERSION 3.15.0)
project(Gris.Assert VERSION 0.1.0)

option(GRIS_ASSERT_BUILD_TESTS "Build the test suite." ON)

########################################################################

include("cmake/standard_project_settings.cmake")
include("cmake/compiler_warnings.cmake")

if (GRIS_ASSERT_BUILD_TESTS)
  include(CTest)
  include("cmake/test_compile_fail.cmake")
  include("cmake/test_compile_success.cmake")
endif()

########################################################################

setup_standard_project_settings()

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_11)

add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

add_library(Gris.Assert)

target_sources(Gris.Assert PRIVATE
  "src/gris/assert.cpp"
  "include/gris/assert.h"
)

target_include_directories(Gris.Assert PUBLIC
  "include"
)

target_link_libraries(Gris.Assert PRIVATE
  project_warnings
  project_options
)

########################################################################

if (GRIS_ASSERT_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
