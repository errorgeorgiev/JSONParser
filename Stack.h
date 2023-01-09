#pragma once

#include <iostream>
const int NUM = 1000; //default capacity of stack

class Stack {
private:
    int n;
    char* arr;
    int t;	

public:
    Stack();
    Stack(int);
    Stack(const Stack& );
    Stack& operator = (const Stack& );
    ~Stack();
	
    void push(const char&);
    char pop();
    char& top() const; 
    bool isEmpty() const;
    int size() const;
    void print();
};
