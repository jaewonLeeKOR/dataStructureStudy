#include<iostream>
#include<string>
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
    public:
        Node<N> *node;
        Iterator(Node<N> *n):node(n) {}
        Iterator<N> &operator++() {this->node = this->node->next; return *this;}
        Iterator<N> &operator--() {this->node = this->node->prev; return *this;}
        const bool operator==(const Iterator<N> &iter) const {return this->node == iter->node;}
        const bool operator!=(const Iterator<N> &iter) const {return this->node != iter->node;}
        Node<N> &operator*() const {return *(this->node);}
    };
    const int size() const {return sequenceSize;}
    const bool empty() const {return sequenceSize==0;}
    Iterator<T> &front() {Iterator<T> iter(header->next); return *iter;}
    Iterator<T> &rear() {Iterator<T> iter(trailer); return *iter;}
    void insert(Iterator<T> iter, T value);
    void insertFront(T value) {insert(front(), value);}
    void insertRear(T value) {insert(rear(), value);}
    T erase(Iterator<T> iter);
    T eraseFront() {erase(front());}
    T eraseRear() {erase(--rear());}
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
    Node<T> *currentNode = iter.node;
    Node<T> *prevNode = currentNode->prev;
    Node<T> *newNode = new Node<T>(value);
    currentNode->prev = newNode;
    prevNode->next = newNode;
    newNode->next = currentNode;
    newNode->prev = prevNode;
    sequenceSize++;
}
template<typename T>
T Sequence<T>::erase(Iterator<T> iter)
{
    Node<T> *currentNode = iter.node;
    Node<T> *prevNode = currentNode->prev;
    Node<T> *nextNode = currentNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    T res = currentNode->element;
    delete currentNode;
    sequenceSize--;
    return res;
}
template<typename T>
void Sequence<T>::clear()
{
    while(empty())
        erase(front());
}
template<typename T>
T Sequence<T>::at(int index) const
{
    Iterator<T> *iter = front();
    for(int i=0; i<index;i++)
        ++iter;
    return iter->node->element;
}
template<typename T>
T Sequence<T>::operator[](int index) const
{
    Iterator<T> *iter = front();
    for(int i=0;i<index;i++)
        ++iter;
    return iter->node->element;
}
template<typename T>
int Sequence<T>::nowIndex(Iterator<T> iter) const
{
    int count = 0;
    for(Iterator<T> *i=front(); i!=iter; ++iter)
        count++;
    return count;
}
template<typename T>
void Sequence<T>::print() const
{
    for(Iterator<T> *i=front(); i!=rear(); ++i)
        cout << i->node->element << " ";
    cout << "\n";
}
template<typename T>
void Sequence<T>::printReverse() const
{
    for(Iterator<T> *i=rear(); i!=front(); --i)
        cout << i->node->prev->element << " ";
    cout << "\n";
}
int main()
{
    int testCase;
    string s;
    Sequence<int> sq;
    Sequence<int>::Iterator<int> iter = sq.front();
    cin >> testCase;
    for(int i=0;i<testCase;i++)
    {
        cin >> s;
        if(s=="++")
        {
            ++iter;
        }
        else if(s=="--")
        {
            --iter;
        }
        else if(s=="*")
        {
            cout << (*iter).element << "\n";
        }
        else if(s=="size")
        {
            cout << sq.size() << "\n";
        }
        else if(s=="empty")
        {
            if(sq.empty())
                cout << "Sequence is Empty.\n";
            else
                cout << "Sequence is not Empty.\n";
        }
        else if(s=="front")
        {
            iter = sq.front();
        }
        else if(s=="rear")
        {
            iter = sq.rear();
        }
        else if(s=="insert")
        {
            int e;
            cin >> e;
            sq.insert(iter,e);
        }
        else if(s=="insertFront")
        {
            int e;
            cin >> e;
            sq.insertFront(e);
        }
        else if(s=="insertRear")
        {
            int e;
            cin >> e;
            sq.insertRear(e);
        }
        else if(s=="erase")
        {
            sq.erase(iter);
        }
        else if(s=="eraseFront")
        {
            sq.eraseFront();
        }
        else if(s=="eraseRear")
        {
            sq.eraseRear();
        }
        else if(s=="clear")
        {
            sq.clear();
        }
        else if(s=="at")
        {
            int e;
            cin >> e;
            cout << sq.at(e) << "\n";
        }
        else if(s=="[]")
        {
            int e;
            cin >> e;
            cout << sq[e] << "\n";
        }
        else if(s=="nowIndex")
        {
            cout << sq.nowIndex(iter) << "\n";
        }
        else if(s=="print")
        {
            sq.print();
        }
        else if(s=="printReverse")
        {
            sq.printReverse();
        }
        else if(s=="q")
            break;
    }
}