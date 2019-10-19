cmake_minimum_required(VERSION 3.14.0)
project(Gris.Assert VERSION 0.1.0)

option(GRIS_ASSERT_BUILD_TESTS "Build the test suite." OFF)

########################################################################

if (GRIS_ASSERT_BUILD_TESTS)
    include(CTest)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

########################################################################

add_library(Gris.Assert "src/gris/assert.cpp" "include/gris/assert.h")

target_include_directories(Gris.Assert PUBLIC "include")

########################################################################

if (GRIS_ASSERT_BUILD_TESTS)
    add_subdirectory(tests)
endif()
