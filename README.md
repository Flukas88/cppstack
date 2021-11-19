# cppstack
[![Build Status](https://travis-ci.org/Flukas88/cppstack.svg?branch=master)](https://travis-ci.org/Flukas88/cppstack)


## Abstract

A Reverse Polish notation calculator in *modern C++17* with python unittests


### How to build it
```bash
      mkdir build && cd $_
      cmake ../
      make
      cd .. && ln -s build/cppstack cppstack
```

### How to use it
```bash
      ./cppstack "8 2 5 x + 1 3 2 x + 4 - /"
```

### How to Unittest

To manually run them (after build)
```python
    python UnitTest.py
```


### Compatibility

Tested on
  - *Visual Studio Community 2017* 
  - *Visual Studio Community 2019* 
  - *gcc* on MacOS amd64 and arm64 (9.x, 11.x)
  - *llvm* on MacOS amd64 and arm64 
