cmake_minimum_required(VERSION 3.12)
project(cppstack)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(cppstack
        include/stack.hpp
        include/utils.hpp
        include/catch.hpp
        src/stack.cpp
        src/utils.cpp
        cppstack.cbp
        main.cpp
        README.md
        requirements.txt
        UnitTest.py)
