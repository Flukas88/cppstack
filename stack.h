//
// Created by lfrances on 26-Jul-17.
//

#ifndef CPPSTACK_STACK_H
#define CPPSTACK_STACK_H

#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifndef size
#define size 25
#endif

class Stack {

public:
    double pop();
    void push(double item);
    bool is_number(const std::string &s);
    vector<string> split(const char *str, char c = ' ') {
        vector<string> result;
        do {
            const char *begin = str;
            while (*str != c && *str)
                str++;
            result.emplace_back(string(begin, str));
        } while (0 != *str++);

        return result;
    };

private:
    vector<double> st;
};

void Stack::push(double item) { st.push_back(item); }

double Stack::pop() {
    double item;
    item = st.back();
    st.pop_back();
    return (item);
}

bool Stack::is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

#endif // CPPSTACK_STACK_H
