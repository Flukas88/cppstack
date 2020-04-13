cmake_minimum_required(VERSION 3.2)
project(cppstack VERSION 0.2.3 LANGUAGES CXX)

### Standard
#set(CMAKE_CXX_STANDARD 11)
#
set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_library(stacklib
  src/stack.cpp
  src/utils.cpp
  include/stack.hpp
  include/utils.hpp
)

target_compile_features(stacklib PUBLIC cxx_std_17)

# include config
include_directories(include)

# exec config
add_executable(cppstack main.cpp )
target_link_libraries(cppstack PRIVATE stacklib)

