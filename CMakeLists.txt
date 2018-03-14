cmake_minimum_required(VERSION 3.2)
project(cppstack  VERSION 0.2.1 LANGUAGES CXX)

# language config
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

# source file config
set(SOURCE_FILES main.cpp src/utils.cpp src/stack.cpp)

# flags config
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # using Clang
    set(CMAKE_CXX_FLAGS "-fprofile-instr-generate -fcoverage-mapping")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # using GCC
    set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
endif()

# include config
include_directories(include src)

# exec config
add_executable(cppstack ${SOURCE_FILES})
