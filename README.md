# cppstack
 [![Build Status](https://travis-ci.org/Flukas88/cppstack.svg?branch=master)](https://travis-ci.org/Flukas88/cppstack)
 
 [![codecov](https://codecov.io/gh/Flukas88/cppstack/branch/master/graph/badge.svg)](https://codecov.io/gh/Flukas88/cppstack)



### What is it about

A Reverse Polish notation calculator in *modern C++11* with python unittests


### How to use it
```bash
      ./cppstack "8 2 5 x + 1 3 2 x + 4 - /"
```
### Compatibility

Tested with travis

  - *clang* [GNU/Linux, macOS]
  - *gcc* [GNU/Linux]
  
Not tested with travis
  - *Visual Studio Community 2017* 
  - *gcc* (MinGW GCC 6.4.0) via CLion

### Unittest

Tests are run on commit via travis.  
To manually run them (after build)
```python
    python UnitTest.py
```