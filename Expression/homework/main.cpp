#include "expression.h"
#include <iostream>
#include <cassert>

using namespace std;
using namespace oop;

int main() {
    // Inheritance in action.
    //Constant and BinaryPlus are both children of Expression
    Constant c1(1);
    Constant c2(2);
    Constant c3(3);
    BinaryPlus bp(c1, c2);
    BinaryPlus bp2(bp, c3);
    string c1plusc2plusc3 = bp2.toString();
    double result = bp2.evaluate();
    cout << c1plusc2plusc3 << " = " << result << endl;
    assert(result == 6);
    // Polymorphism in action
    vector<const Expression*> expressions = {&c1, &c2, &c3, &bp, &bp2};
    for (const Expression* e_ptr : expressions) {
        const Expression& e = *e_ptr;
        printExpression(e);
    }
    return 0;
}