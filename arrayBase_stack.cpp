#include<iostream>
#include<string>
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
        return (T)NULL;
    }
    return stack[--stackSize] = (T)NULL;
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

int main()
{
    int testCase, size;
    cin >> testCase;
    cout << "stack size : ";
    cin >> size;
    Stack<int> stack(size);
    string s;
    for(int i=0;i<testCase;i++)
    {
        cin >> s;
        if(s=="size")
        {
            cout << "Size : " << stack.size() << "\n";
        }
        else if(s=="empty")
        {
            if(stack.empty())
                cout << "Stack is empty!\n";
            else
                cout << "Stack is not empty\n";
        }
        else if(s=="push")
        {
            int e;
            cin >> e;
            stack.push(e);
        }
        else if(s=="pop")
        {
            if(stack.empty())
                stack.pop();
            else
                cout << stack.pop() << "\n";
        }
        else if(s=="print")
        {
            stack.print();
        }
        else if(s=="q")
        {
            break;
        }
    }
}