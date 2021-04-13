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
    inline const int size() const {return listSize;}
    inline const bool empty() const {return listSize==0;}
    void insertHead(T element);
    void insertTail(T element);
    void removeHead();
    void removeTail();
    T showHead() const;
    T showTail() const;
};

template<typename T>
void LinkedList<T>::insertHead(T element)
{
    Node<T> newNode = new Node<T>(element);
    if(empty())
    {
        headNode = newNode;
        tailNode = newNode;
    }
    else
    {
        newNode->next = headNode;
        headNode = newNode;
    }
    listSize++;
}

int main(){}