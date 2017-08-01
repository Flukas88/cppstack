cmake_minimum_required(VERSION 3.8)
project(cppstack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp stack.h)
add_executable(cppstack ${SOURCE_FILES})