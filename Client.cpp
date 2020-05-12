/*
Vitaliy Stepanov
CS300A Assignment 2
Professor Dr. Fatma Cemile Serce

This program takes user inputs and uses a calculator to make operations
*/

#include "Calculator.h"
#include <iostream>
using namespace std;

int main() {
    Calculator *c = new Calculator;
    string input;
    getline(cin, input);

    while(input != "\\") { // while loop instead of do while loop for else statement to not take in "\"
        if (input == "<<") { 
            c->print(); // calls calculators print function of input is <<
        } else if (input == "^") {
            c->callPop(); // calls calculators to remove top element of stack
        } else if (input == "+") {
            c->add(); // calls calculator to add two integers
        } else if (input == "-") {
            c->subtract(); // calls calculator to subtract two integers
        } else if (input == "*") {
            c->multiply(); // calls calculator to multiply two integers
        } else if (input == "/") {
            c->divide(); // calls calculator to divide two integers
        } else if (input == "%") {
            c->mod(); // calls calculator to get the remainder of two integers
        } else {
            int num = stoi(input); // converts next string token into an integer
            c->callPush(num); // puts integer on top of stack
        }    
        getline (cin, input); // gets next token from user input
    }
    return 0;
}