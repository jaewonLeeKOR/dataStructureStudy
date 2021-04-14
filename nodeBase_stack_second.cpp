#include<iostream>

template<typename T>class Stack;

template<typename T>
class Node{
    T memberElement;
    Node<T> *next;
    Node(T e):memberElement(e),next(nullptr) {}
    friend class Stack<T>;
};

template<typename T>
class Stack{
    int stackSize;
    Node<T> *topNode;
public:
    Stack():stackSize(0),topNode(nullptr) {}
    inline const int size() const {return stackSize;}
    inline const bool empty() const {return stackSize==0;}
    T top() const;
    void push(T);
    T pop();
    void print() const;
};

int main(){}