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

# source files config
file(GLOB SOURCE_FILES  ${CMAKE_SOURCE_DIR}/src/*.cpp)
set(MAIN_FILE ${CMAKE_SOURCE_DIR}/main.cpp)

# include config
include_directories(include)

# exec config
add_executable(cppstack ${MAIN_FILE} ${SOURCE_FILES} )
