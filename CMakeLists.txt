cmake_minimum_required(VERSION 3.18)
project(cppstack
  DESCRIPTION "A Reverse Polish notation calculator in modern C++11 with unittests"
  VERSION "0.1"
  LANGUAGES CXX
  )

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        argparse
        GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

include_directories(${PROJECT_SOURCE_DIR}/include)
set(HEADER_FILES ${PROJECT_SOURCE_DIR}/include/stack.hpp ${PROJECT_SOURCE_DIR}/include/utils.hpp)
set(SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/stack.cpp ${PROJECT_SOURCE_DIR}/src/utils.cpp)

set(ALL_SRCS
        ${HEADER_FILES}
        ${SOURCE_FILES}
)

add_executable(cppstack ${ALL_SRCS} main.cpp)
target_link_libraries(cppstack argparse)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.5.2 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests ${ALL_SRCS} test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
