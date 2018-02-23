cmake_minimum_required(VERSION 3.2)
project(cppstack  VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)


set(SOURCE_FILES main.cpp src/utils.cpp src/stack.cpp)
set(HEADERS_FILES include/stack.hpp include/utils.hpp)

add_executable(cppstack ${SOURCE_FILES})

target_include_directories(cppstack
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )


option(USE_CLANG "build application with clang" OFF) # OFF is the default

if(USE_CLANG)
    set(CMAKE_CXX_FLAGS "-fprofile-instr-generate -fcoverage-mapping")
endif(USE_CLANG)