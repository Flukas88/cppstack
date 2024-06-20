#include "stack.hpp"

#include <cmath>

void Stack::push(const float item) {
  st.push_back(item); 
}

auto Stack::pop() ->  float {
  float item = NAN;
  item = st.back();
  st.pop_back();
  return item;
}

