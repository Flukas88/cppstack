#include "stack.hpp"

#include <cmath>

void Stack::push(const double item) { 
  st.push_back(item); 
}

auto Stack::pop() ->  double {
  double item = NAN;
  item = st.back();
  st.pop_back();
  return item;
}

