# cppstack

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
      ./build/cppstack "8 2 5 x + 1 3 2 x + 4 - /"
```

### How to Unittest

To manually run them (after build)

```bash
    ./build/tests
```

### Compatibility

Tested on

- *Visual Studio Community 2017* and *Visual Studio Community 2019*
- *gcc* on MacOS amd64 and arm64 (9.x, 11.x) and WSLv2 (Ubuntu 20.04 LTS) amd64 (9.3)
- *llvm* on MacOS amd64 and arm64 (13.x)
