#include "stack.hpp"

void Stack::push(const double item) { 
  st.push_back(item); 
}

const double Stack::pop() {
  double item;
  item = st.back();
  st.pop_back();
  return item;
}

