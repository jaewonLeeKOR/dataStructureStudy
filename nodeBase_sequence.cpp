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
        Iterator<N> &operator++();
        Iterator<N> &operator--();
        const bool operator==(const Iterator<N> &iter) const;
        const bool operator!=(const Iterator<N> &iter) const;
        Node<N> &operator*() const;
    };
    const int size() const {return sequenceSize;}
    const bool empty() const;
    const bool full() const;
    Iterator<T> &front();
    Iterator<T> &rear();
    void insert(Iterator<T> iter, T value);
    void insertFront(T value);
    void insertRear(T value);
    T erase(Iterator<T> iter);
    T eraseFront();
    T eraseRear();
    void clear();
    T at(int index) const;
    T operator[](int index) const;
    int noewIndex(Iterator<T> iter) const;
    void print() const;
    void printReverse() const;
};