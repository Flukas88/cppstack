cmake_minimum_required(VERSION 3.2)
project(cppstack  VERSION 0.2.1 LANGUAGES CXX)

# language config
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

# source files config
file(GLOB SOURCE_FILES  ${CMAKE_SOURCE_DIR}/src/*.cpp)
set(MAIN_FILE ${CMAKE_SOURCE_DIR}/main.cpp)

# flags config
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # using Clang
    set(CMAKE_CXX_FLAGS "-fprofile-instr-generate -fcoverage-mapping")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # using GCC
    set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
endif()

# include config
include_directories(include)

# exec config
add_executable(cppstack ${MAIN_FILE} ${SOURCE_FILES} )
