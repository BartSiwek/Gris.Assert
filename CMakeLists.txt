cmake_minimum_required(VERSION 3.14.0)
project(Gris.Assert VERSION 0.1.0)

include(CTest)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_library(Gris.Assert "src/gris/assert.cpp" "include/gris/assert.h")

target_include_directories(Gris.Assert PUBLIC "include")

add_subdirectory(tests)
