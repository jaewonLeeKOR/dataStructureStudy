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
    inline const int size() const {return stackSize;}
    inline const bool empty() const {return stackSize==0;}
    inline const bool full() const {return stackSize==capacity;}
    inline const T top() const {return empty()?(T)NULL:stack[stackSize-1];}
    void push(T);
    T pop();
    void print() const;
};

template<typename T>
void Stack<T>::push(T e)
{
    if(full())
    {
        cout << "Stack is Full.\n";
        return;
    }
    stack[stackSize++] = e;
}

template<typename T>
T Stack<T>::pop()
{
    if(empty())
    {
        cout << "Stack is Empty.\n";
        return;
    }
    stack[--stackSize] = (T)NULL;
}

template<typename T>
void Stack<T>::print() const
{
    if(empty())
    {
        cout << "Stack is Empty.\n";
        return;
    }
    for(int i=stackSize-1;i>=0;i--)
        cout << stack[i] << " ";
    cout << "\n";
}

int main() {}