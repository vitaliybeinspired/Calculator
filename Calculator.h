/*
Vitaliy Stepanov
CS300A Assignment 2
Professor Dr. Fatma Cemile Serce
 
Calculator with functions to manipulate data values using LinkedStack data structure
*/

#ifndef Calculator_h
#define Calculator_h
#include <iostream>
using namespace std;

class Calculator {
    private:
        LinkedStack<int> *stack;
    
    public:
        Calculator(); // constructor
        void print(); // calls stack print to print data of linkedlist
        void add(); // adds two integers on top of stack
        void subtract(); // subtracts two integers on top of stack
        void multiply(); // multiplies two integers on top of stack
        void divide(); // divides two inegers on top of stack
        void mod(); // gets the remainder of two integers on top of stack
        void callPop(); // removes top element of stack
        void callPush(int); // adds element to top of stack
        ~Calculator(); // destructor
};

// constructor
Calculator::Calculator() {
}

// destructor
Calculator::~Calculator() {
    delete stack;
}

// adds two integers on top of stack
void Calculator::add() {
    if (stack->getSize() > 1) {
        int num1 = stack->getTop();
        stack->pop();
        int num2 = stack->getTop();
        stack->pop();
        int result = num1 + num2;
        stack->push(result); 
    } else {
        throw "Not enough operands!";
    }
}

// subtracts two integers on top of stack
void Calculator::subtract() {
    if (stack->getSize() > 1) {
        int num1 = stack->getTop();
        stack->pop();
        int num2 = stack->getTop();
        stack->pop();
        int result = num1 - num2;
        stack->push(result);
    } else {
        throw "Not enough operands!";
    }
}

// multiplies two integers on top of stack
void Calculator::multiply() {
    if (stack->getSize() > 1) {
        int num1 = stack->getTop();
        stack->pop();
        int num2 = stack->getTop();
        stack->pop();
        int result = num1 * num2;
        stack->push(result);
    } else {
        throw "Not enough operands!";
    }
}

// divides two integers on top of stack
void Calculator::divide() {
    if (stack->getSize() > 1) {
        int num1 = stack->getTop();
        stack->pop();
        int num2 = stack->getTop();
        stack->pop();
        int result = num1 / num2;
        stack->push(result);
    } else {
        throw "Not enough operands!";
    }
}

// gets the remainder of two integers on top of stack
void Calculator::mod() {
    if (stack->getSize() > 1) {
        int num1 = stack->getTop();
        stack->pop();
        int num2 = stack->getTop();
        stack->pop();
        int result = num1 % num2;
        stack->push(result);
    } else {
        throw "Not enough operands!";
    }
}

// removes top element of stack
void Calculator::callPop() {
    stack->pop();
}

// pushes element to top of stack
void Calculator::callPush(int num) {
    stack->push(num);
}

// prints all data in stack
void Calculator::print() {
    stack->printList();
}
#endif