#inlcude<iostream>
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
        Node<I> *node;
        Iterator(Node<I> *n):node(n) {}
        Iterator &operator++() {this->node = this->node->next; return *this;}
        Iterator &operator--() {this->node = this->node->prev; return *this;}
        bool operator==(const Iterator& iter) {return this->node == iter.node;}
        bool operator!=(const Iterator& iter) {return this->node != iter.node;}
        bool operator*() {return *(this->node);}
    }
    int size() const {return listSize;}
    bool empty() const {return listSize == 0;}
    Iterator &begin() {return Iterato(header->next);}
    Iterator &end() {return Iterator(trailer);}
    void insert(const Iterator& iter, T value);
    void insertFront(T value);
    void insertEnd(T value);
    T erase(const Iterator& iter);
    T eraseFront();
    T eraseEnd();
    void print() const;
    void printReverse() const;
}