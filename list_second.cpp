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
    Iterator<T> begin() {return Iterator<T>(header->next);}
    Iterator<T> end() {return Iterator<T>(trailer);}
    void insert(const Iterator<T>& iter, T value);
    void insertFront(const T& value) {insert(begin(), value);}
    void insertEnd(const T& value) {insert(end(), value);}
    T erase(const Iterator<T>& iter);
    T eraseFront() {return erase(begin());}
    T eraseEnd() {return erase(trailer->prev);}
    void print();
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
template<typename T>
T List<T>::erase(const Iterator<T>& iter)
{
    Node<T> *tmp = iter.node;
    Node<T> *nextNode = tmp->next;
    Node<T> *prevNode = tmp->prev;
    T res = tmp->element;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete tmp;
    return res;
}
template<typename T>
void List<T>::print()
{
    for(Iterator<T> iter = begin(); iter != end(); ++iter)
        cout << iter.node->element << " ";
    cout << "\n";
}
template<typename T>
void List<T>::printReverse() const
{
    for(Iterator<T> iter = end(); iter != begin(); --iter)
        cout << iter.node->prev->element << " ";
    cout << "\n";
}
int main()
{
    int testCase;
    string s;
    cin >> testCase;
    List<int> l;
    List<int>::Iterator<int> iter = l.begin();
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
        else if(s=="empty")
        {
            if(l.empty())
                cout << "List is empty.\n";
            else
                cout << "List is not empty.\n";
        }
        else if(s=="size")
        {
            cout << "size : " << l.size() << "\n";
        }
        else if(s=="end")
        {
            iter = l.end();
        }
        else if(s=="begin")
        {
            iter = l.begin();
        }
        else if(s=="insert")
        {
            int n,e;
            cout << "1.insertFront 2.insertEnd 3.insert(iter)\n";
            cin >> n;
            cout << "input element.\n";
            cin >> e;
            switch (n)
            {
                case 1:
                    l.insertFront(e);
                    break;
                case 2:
                    l.insertEnd(e);
                    break;
                case 3:
                    l.insert(iter,e);
                    break;
                default:
                    cout << "select in 1,2,3.\n";
                    break;
            }
        }
        else if(s=="erase")
        {
            if(l.empty())
                cout << "List is empty,\n";
            else
            {
                int n;
                cout << "1.eraseFront 2.eraseEnd 3.erase(iter)\n";
                cin >> n;
                switch (n)
                {
                case 1:
                    l.eraseFront();
                    break;
                case 2:
                    l.eraseEnd();
                    break;
                case 3:
                    l.erase(iter);
                    break;
                default:
                    cout << "select in 1,2,3.\n";
                    break;
                }
            }
        }
        else if(s=="print")
        {
            if(l.empty())
                cout << "List is empty.\n";
            else
                l.print();
        }
    }
}