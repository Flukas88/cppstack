#include "stack.hpp"

void Stack::push(double item) { st.push_back(item); }

double Stack::pop() {
  double item;
  item = st.back();
  st.pop_back();
  return item;
}

