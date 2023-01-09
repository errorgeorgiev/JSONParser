#include "Stack.h"


Stack::Stack()
{
    n = NUM;
    arr = new char[n];
    t = -1;
}

Stack::Stack(int cap = NUM)
{
    n = cap;
    arr = new char[n];
    t = -1;
}
Stack::Stack(const Stack& other)
{
    n = other.n;
    t = other.t;
    arr = new char[n];

    for(int i = 0; i <= t; i++)
    {
        arr[i] = other.arr[i];
    }
}
Stack& Stack::operator = (const Stack& other)
{
    if(this!=&other)
    {
        delete[] arr;
        n = other.n;
        t = other.t;
        arr = new char[n];

        for(int i = 0; i <= t; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}
Stack::~Stack()
{
    delete[] arr;
}
void Stack::push(const char& obj)
{
    if(size() == n)
    {
        std::cout << "Stack overflow." << std::endl;
        return;
    }
    t++;
    arr[t] = obj;
}
char Stack::pop()
{
    if(isEmpty())
    {
        std::cout << "Access to empty stack." << std::endl;
        return 1;
    }
    return arr[t--];
}
void Stack::print()
{
    while(!isEmpty())
    {
        std::cout << top();
        pop();
    }
    std::cout << std::endl;
}
char& Stack::top() const
{
    return arr[t];
}
bool Stack::isEmpty() const
{
    return (t < 0);
}
int Stack::size() const
{
    return t+1;
}
