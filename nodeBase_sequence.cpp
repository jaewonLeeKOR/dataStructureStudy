#include<iostream>
using namespace std;
template<typename T>
class Sequence
{
    template<typename N>
    struct Node
    {
        N element;
        Node<N> *prev;
        Node<N> *next;
        Node(N e):element(e),prev(nullptr),next(nullptr) {}
    };
    int sequenceSize;
    Node<T> *header;
    Node<T> *trailer;
public:
    Sequence():sequenceSize(0)
    {
        header = new Node<T>((T)NULL);
        trailer = new Node<T>((T)NULL);
        header->next = trailer;
        trailer->next = header;
        sequenceSize++;
    }
    template<typename N>
    class Iterator
    {
        Node<N> *node;
    public:
        Iterator(Node<N> *n):node(n) {}
        Iterator<N> &operator++() {this->node = this->node->next; return *this;}
        Iterator<N> &operator--() {this->node = this->node->prev; return *this;}
        const bool operator==(const Iterator<N> &iter) const {return this->node == iter->node;}
        const bool operator!=(const Iterator<N> &iter) const {return this->node != iter->node;}
        Node<N> &operator*() const {return this->node;}
    };
    const int size() const {return sequenceSize;}
    const bool empty() const {return sequenceSize==0;}
    Iterator<T> &front() {return Iterator<T>(header->next);}
    Iterator<T> &rear() {return Iterator<T>(trailer);}
    void insert(Iterator<T> iter, T value);
    void insertFront(T value) {insert(front(), value);}
    void insertRear(T value) {insert(rear(), value);}
    T erase(Iterator<T> iter);
    T eraseFront();
    T eraseRear();
    void clear();
    T at(int index) const;
    T operator[](int index) const;
    int nowIndex(Iterator<T> iter) const;
    void print() const;
    void printReverse() const;
};
template<typename T>
void Sequence<T>::insert(Iterator<T> iter, T value)
{
    Node<T> *currentNode = iter->node;
    Node<T> *prevNode = currentNode->prev;
    Node<T> *newNode = new Node<T>(value);
    currentNode->prev = newNode;
    prevNode->next = newNode;
    newNode->next = currentNode;
    newNode->prev = prevNode;
    sequenceSize++;
}