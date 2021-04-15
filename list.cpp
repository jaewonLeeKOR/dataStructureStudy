#include<iostream>
using namespace std;

template<typename T>class List;
template<typename T>class Iterator;

template<typename T>
class Node{
    T memberElement;
    Node<T> *next;
    Node<T> *prev;
    Node(T e):memberElement(e),next(nullptr),prev(nullptr) {}
    friend class List<T>;
    friend class Iterator<T>;
};

template<typename T>
class Iterator{
    Node<T> *pointNode;
public:
    Iterator(Node<T> *n=nullptr):pointNode(n) {}
    Iterator& operator*() {return pointNode;};
    bool operator==(const Iterator& b) const {return pointNode->memberElement==b->memberElement? true:false;}
    Iterator& operator++() {pointNode=pointNode->next;return *this;}
    Iterator operator++(int) {Iterator<T> *iter(pointNode); iter->pointNode=iter->pointNode->next;return iter;}
    Iterator& operator+=(int);
    Iterator& operator--() {pointNode=pointNode->prev;return *this;}
    Iterator operator--(int) {Iterator<T> *iter(pointNode); iter->pointNode=iter->pointNode->next;return iter;}
    Iterator& operator-=(int);
    friend class List<T>;
};

template<typename T>
class List
{
    int listSize;
    Node<T> *headerNode;
    Node<T> *trailerNode;
public:
    List():listSize(0),headerNode(nullptr),trailerNode(nullptr) {}
    inline const int size() const {return listSize;}
    inline const bool empty() const {return size()==0;}
    Iterator<T>& begin();
    Iterator<T>& end();
    void insertFront(T);
    void insertEnd(T);
    void eraseFront();
    void eraseEnd();
    void insert(Iterator<T>, T);
    void erase(Iterator<T>, T);
    void print() const;
};

template<typename T>
Iterator<T>& Iterator<T>::operator+=(int plus)
{
    for(int i=0;i<plus;i++)
        this++;
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator-=(int minus)
{
    for(int i=0;i<minus;i++)
        this--;
    return *this;
}

template<typename T>
Iterator<T>& List<T>::begin()
{
    Iterator<T> *tmp(headerNode->next);
    return tmp;
}

int main() {}