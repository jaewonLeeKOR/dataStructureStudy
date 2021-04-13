#include<iostream>
using namespace std;

template<typename T>class LinkedList;

template <typename T>
class Node{
    T memberElement;
    Node *next;
    Node(T element):memberElement(element) {}
    friend class LinkedList<T>;
};

template <typename T>
class LinkedList{
    int listSize;
    Node<T> *headNode;
    Node<T> *tailNode;
public:
    LinkedList():headNode(nullptr),tailNode(nullptr),listSize(0) {}
    const int size() const;
    const bool empty() const;
    void inserthead(T element);
    void insertTail(T element);
    void removeHead();
    void removeTail();
    T showHead() const;
    T showTail() const;
};

int main(){}