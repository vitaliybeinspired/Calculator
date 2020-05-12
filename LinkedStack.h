/*
Vitaliy Stepanov
CS300A Assignment 2
Professor Dr. Fatma Cemile Serce
 
Stack data structure that uses LinkedLists to store generic data 
*/


#ifndef LinkedStack_h
#define LinkedStack_h
using namespace std;
#include <iostream>

// generic linkedlist data structor node
template <class T> 
struct node {
    T data;
    node<T> *next;
};

template <class T>
class LinkedStack:public StackADT<T> {
    private:
        node<T> *top; // pointer to top of stack
        int size; // size of stack
        
    public:
        LinkedStack(); // constructor
        void push(T&); // puts element to top of stack
        void pop(); // removes element from top of stack
        T getTop(); // retrieves element from top of stack
        bool isEmpty(); // returns boolean if stack is empty
        void destroy(); // deletes all linkedlists nodes
        ~LinkedStack(); // destructor
        int getSize() const; // returns size of stack
        void printList(); // prints all of linkedlists data
        template <class A>
        friend ostream& operator<<(ostream& os, LinkedStack<A>& list);
};

// constructor
template <class T>
LinkedStack<T>::LinkedStack() {
    top = NULL;
    size = 0;
}

// puts elements on top of stack
template <class T>
void LinkedStack<T>::push(T& item) {
    if (size == 0) {
        node<T> *newNode = new node<T>;
        newNode->data = item;
        newNode->next = NULL;
        top = newNode;
        size++;
    } else {
        node<T> *newNode = new node<T>;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
        size++;
    }
    
}

// removes element from top of stack
template <class T>
void LinkedStack<T>::pop() {
    if(size > 0) {
        node<T> *temp = top;
        top = top->next;
        delete temp;
        size--;
    } if (size == 0) {
        top = NULL;
    }
}

// retrieves data from top of stack
template <class T>
T LinkedStack<T>::getTop() {
    if (!isEmpty()) {
        return top->data;
    }
}

// returns boolean if stack is empty
template <class T>
bool LinkedStack<T>::isEmpty() {
    return top == NULL;
}

// reallocates memory by deleting all linkedlists
template <class T>
void LinkedStack<T>::destroy() {
    node<T> *temp = top;
    while(temp != NULL) {
        top = top->next;
        delete temp;
        temp = top;
    }
    top = NULL;
    size = 0;
}

// destructor
template <class T>
LinkedStack<T>::~LinkedStack() {
    destroy();
}

// returns size of stack
template <class T>
int LinkedStack<T>::getSize() const {
    return size;
}

// prints all data of linkedlist stack from top to bottom
template <class T>
void LinkedStack<T>::printList() {
    cout << "<";
    node<T> *temp = top;
    while (temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<">"<<endl;
}

// operator<< to print linkedlist
template <class T>
ostream& operator<<(ostream& os, LinkedStack<T>& list) {
    node<T> *temp = list.top;
    while (temp != NULL) {
        os<<temp->data<<" "; 
        temp = temp-next;
    }
    os<<endl;
    return os;
}
#endif