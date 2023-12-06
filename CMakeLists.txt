cmake_minimum_required(VERSION 3.12)
project(cppstack
  DESCRIPTION "A Reverse Polish notation calculator in modern C++11 with unittests"
  VERSION "0.1"
  LANGUAGES CXX
  )

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"      
        )

add_executable(cppstack ${all_SRCS} main.cpp)
