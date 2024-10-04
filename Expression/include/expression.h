#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <iomanip> 

using namespace std;

namespace oop {
/**
* @brief Create Class Expression
*
* @param toString First integer
* @param evaluate Second integer
* @param Expression Destructor
* @return int Sum of a and b
*/

class Expression {
public:
    virtual string toString() const = 0;
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

/**
* @brief Create Class Constant
*
* @param toString
* @param evaluate
* @param Constant constructor that stores the value
*/

class Constant : public Expression {
private:
    double value;  // The stored constant value

public:
    // Constructor that initializes the value
    Constant(double val) : value(val) {}

    // Override the toString method to return the stored value as a string
    std::string toString() const override {
        return std::to_string(value);
    }

    // Override the evaluate method to return the stored value
    double evaluate() const override {
        return value;
    }
};

/**
* @brief Create Class BinaryPlus
*
* @param toString
* @param evaluate
* @param BinaryPlus constructor that takes two expressions for addition
*/

class BinaryPlus : public Expression {
private:
    const Expression& leftExpression;   // Reference to the left expression
    const Expression& rightExpression;  // Reference to the right expression

public:
    // Constructor that takes two references to expressions and stores them
    BinaryPlus(const Expression& left, const Expression& right)
        : leftExpression(left), rightExpression(right) {}

    // Override the evaluate method to return the sum of the results of evaluating both expressions
    double evaluate() const override {
        return leftExpression.evaluate() + rightExpression.evaluate();
    }

    // Override the toString method to return a string representation of the addition
    std::string toString() const override {
        return "(" + leftExpression.toString() + " + " + rightExpression.toString() + ")";
    }
};

/**
* @brief Helper function to print the expression and its evaluated result
*
* @param expr Reference to the expression to be printed
*/

void printExpression(const Expression& expr) {
    // Call the toString() method to get the string representation of the expression
    std::cout << "Expression: " << expr.toString() << std::endl;
    
    // Call the evaluate() method to get the result of the expression
    std::cout << "Result: " << expr.evaluate() << std::endl;
}
    
}  // namespace oop

#endif // DYNAMICARRAY_H