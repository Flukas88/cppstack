#include "stack.h"

int main(int arc, char **argv) {
    Stack thestack;
    vector<string> tokens = thestack.split(argv[1], ' ');
    double op1, op2;

    for (auto token : tokens) {
        if (thestack.is_number(token)) {
            thestack.push(std::stod(token));
        } else {
            if (token.find('+') != string::npos) {
                op1 = thestack.pop();
                op2 = thestack.pop();
                thestack.push(op1 + op2);
            } else if (token.find('-') != string::npos) {
                op1 = thestack.pop();
                op2 = thestack.pop();
                thestack.push(op2 - op1);
            } else if (token.find('x') != string::npos) {
                op1 = thestack.pop();
                op2 = thestack.pop();
                thestack.push(op1 * op2);
            } else if (token.find('/') != string::npos) {
                op1 = thestack.pop();
                op2 = thestack.pop();
                if ((op1 == 0.0) || (op2 == 0.0)) {
                    std::cout << "Division by 0 is not possible! \n";
                } else {
                    thestack.push((op2 / op1));
                }
            }
        }
    }
    double res = thestack.pop();
    std::cout << "Res = " << res << std::endl;
    return 0;
}