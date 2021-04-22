#include<iostream>
using namespace std;
template<typename T>
class List
{
    template<typename N>
    struct Node
    {
        N element;
        Node<N> *prev;
        Node<N> *next;
        Node(N e):element(e),prev(nullptr),next(nullptr) {}
    };
    int listSize;
    Node<T> *header;
    Node<T> *trailer;
public:
    List():listSize(0)
    {
        header = new Node<T>(0);
        trailer = new Node<T>(0);
        header->next = trailer;
        trailer->prev = header;
    }
    template<typename I>
    class Iterator
    {
        public:
        Node<I> *node;
        Iterator(Node<I> *n):node(n) {}
        Iterator &operator++() {this->node = this->node->next; return *this;}
        Iterator &operator--() {this->node = this->node->prev; return *this;}
        bool operator==(const Iterator& iter) {return this->node == iter.node;}
        bool operator!=(const Iterator& iter) {return this->node != iter.node;}
        bool operator*() {return *(this->node);}
    };
    int size() const {return listSize;}
    bool empty() const {return listSize == 0;}
    Iterator<T> &begin() {return Iterator<T>(header->next);}
    Iterator<T> &end() {return Iterator<T>(trailer);}
    void insert(const Iterator<T>& iter, T value);
    void insertFront(T value) {insert(begin(), value);}
    void insertEnd(T value) {insert(end(), value);}
    T erase(const Iterator<T>& iter);
    T eraseFront();
    T eraseEnd();
    void print() const;
    void printReverse() const;
};
template<typename T>
void List<T>::insert(const Iterator<T>& iter, T value)
{
    Node<T> *newNode = new Node<T>(value);
    Node<T> *currentNode = iter.node;
    Node<T> *prevNode = currentNode->prev;
    prevNode->next = newNode;
    currentNode->prev = newNode;
    newNode->next = currentNode;
    newNode->prev = prevNode;
    listSize++;
    return;
}