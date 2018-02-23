#include "stack.h"


std::vector<std::string> Stack::split(const std::string &text, char sep = ' ') {
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}

void Stack::push(double item) { st.push_back(item); }

const double Stack::pop() {
    double item;
    item = st.back();
    st.pop_back();
    return (item);
}

bool Stack::is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

