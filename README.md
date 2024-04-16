# cppstack
[![CMake on a single platform](https://github.com/Flukas88/cppstack/actions/workflows/cmake-single-platform.yml/badge.svg)](https://github.com/Flukas88/cppstack/actions/workflows/cmake-single-platform.yml)

## Abstract

A Reverse Polish notation calculator in *modern C++17* with unittests

### How to build it

```bash
      mkdir build 
      cmake . -Bbuild
      cd build
      make
      cd ..
```

### How to use it

```bash
      ./build/cppstack -e "8 2 5 x + 1 3 2 x + 4 - /"
      ./build/cppstack -h
```

### How to Unittest

To manually run them (after build)

```bash
    ./build/tests
```
