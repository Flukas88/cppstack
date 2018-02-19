cmake_minimum_required(VERSION 3.2)
project(cppstack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)



set(SOURCE_FILES main.cpp stack.h utils.h)
add_executable(cppstack ${SOURCE_FILES})
