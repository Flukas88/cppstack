cmake_minimum_required(VERSION 3.2)
project(cppstack  VERSION 0.2.1 LANGUAGES CXX)

### Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

### Verbosity
set( CMAKE_COLOR_MAKEFILE ON )
set( CMAKE_VERBOSE_MAKEFILE OFF )

#
set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_library(stacklib
  src/stack.cpp
  src/utils.cpp
  include/stack.hpp
  include/utils.hpp
)

# include config
include_directories(include)

# exec config
add_executable(cppstack main.cpp )
target_link_libraries(cppstack PRIVATE stacklib)

