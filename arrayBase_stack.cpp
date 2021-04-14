#include<iostream>
using namespace std;

template<typename T>
class Stack
{
    int stackSize;
    T *stack;
    int capacity;
public:
    Stack(int n):stackSize(0),capacity(n)
    {
        stack = new T[capacity];
        for(int i=0;i<capacity;i++)
            stack[i] = (T)NULL;
    }
    inline const bool empty() const {return stackSize==0;}
    inline const T top() const {return empty()?(T)NULL:stack[stackSize-1];}
    void push(T);
    T pop();
    void print();
};

int main() {}