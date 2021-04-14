#include<iostream>
using namespace std;

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
    T top() const {return topNode->memberElement;}
    void push(T);
    T pop();
    void print() const;
};

template<typename T>
void Stack<T>::push(T element)
{
    Node<T> newNode = new Node<T>(element);
    newNode.next = topNode;
    topNode = newNode;
    stackSize++;
}

template<typename T>
T Stack<T>::pop()
{
    if(empty())
    {
        cout << "Stack is empty!\n";
        return (T)NULL;
    }
    Node<T> tmp = topNode;
    topNode = tmp->next;
    delete topNode;
    stackSize--;
}

int main(){}