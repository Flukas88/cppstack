# cppstack
[![Build Status](https://travis-ci.org/Flukas88/cppstack.svg?branch=master)](https://travis-ci.org/Flukas88/cppstack)


## Abstract

A Reverse Polish notation calculator in *modern C++17* with unittests


### How to build it
```bash
      git submodule init && git submodule update
      mkdir build && cd $_
      cmake ../
      make
      cd .. && ln -s build/cppstack cppstack
      ln -s build/cppstack_test cppstack_test
```

### How to use it
```bash
      ./cppstack "8 2 5 x + 1 3 2 x + 4 - /"
```

### How to Unittest

To manually run them (after build)
```bash
    ./cppstack_test
```


### Compatibility

Tested on
  - *Visual Studio Community 2017* 
  - *Visual Studio Community 2019* 
  - *gcc* on MacOS amd64 and arm64 (9.x, 11.x)
  - *llvm* on MacOS amd64 and arm64 
