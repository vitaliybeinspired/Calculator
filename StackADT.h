/*
Vitaliy Stepanov
CS300A Assignment 2
Professor Dr. Fatma Cemile Serce
 
Abstract data type for stack 
*/

#ifndef StackADT_h
#define StackADT_h

template <class T>
class StackADT {
    public:
        virtual void push(const T&) = 0;
        virtual void pop() = 0;
        virtual T getTop() = 0;
        virtual bool isEmpty() = 0;
        virtual void destroy() = 0;
};
#endif