#include<iostream>
#include<string>
using namespace std;

template<typename T>class List;
template<typename T>class Iterator;

template<typename T>
class Node{
    T memberElement;
    Node<T> *next;
    Node<T> *prev;
    Node<T>(T e=(T)NULL):memberElement(e),next(nullptr),prev(nullptr) {}
    friend class List<T>;
    friend class Iterator<T>;
};

template<typename T>
class Iterator{
    Node<T> *pointNode;
public:
    Iterator(Node<T> *n=nullptr):pointNode(n) {}
    //B Node<T>& operator*() {return pointNode;};
    bool operator==(const Iterator &b) const {return pointNode->memberElement==b->memberElement? true:false;}
    Iterator &operator++() {pointNode=pointNode->next;return *this;}
    Iterator operator++(int) {Iterator<T> *iter(pointNode); iter->pointNode=iter->pointNode->next;return iter;}
    Iterator &operator+=(int);
    Iterator &operator--() {pointNode=pointNode->prev;return *this;}
    Iterator operator--(int) {Iterator<T> *iter(pointNode); iter->pointNode=iter->pointNode->next;return iter;}
    Iterator &operator-=(int);
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
    Iterator<T> begin();
    Iterator<T> end();
    void insertFront(T);
    void insertEnd(T);
    void eraseFront();
    void eraseEnd();
    void insert(Iterator<T>, T);
    void erase(Iterator<T>);
    void print() const;
};

template<typename T>
Iterator<T> &Iterator<T>::operator+=(int plus)
{
    for(int i=0;i<plus;i++)
        this;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator-=(int minus)
{
    for(int i=0;i<minus;i++)
        this--;
    return *this;
}

template<typename T>
Iterator<T> List<T>::begin()
{
    return Iterator<T>(headerNode->next);
}

template<typename T>
Iterator<T> List<T>::end()
{
    Iterator<T> tmp(trailerNode->prev);
    return tmp;
}

template<typename T>
void List<T>::insertFront(T e)
{
    Iterator<T> tmp(headerNode->next);
    insert(tmp,e);
}

template<typename T>
void List<T>::insertEnd(T e)
{
    Iterator<T> tmp(trailerNode);
    insert(tmp, e);
}

template<typename T>
void List<T>::eraseFront()
{
    Iterator<T> tmp(begin());
    erase(tmp);
}

template<typename T>
void List<T>::eraseEnd()
{
    Iterator<T> tmp(end());
    erase(tmp);
}

template<typename T>
void List<T>::insert(Iterator<T> iter, T e)
{
    Node<T> *newNode = new Node<T>(e);
    Node<T> *currentNode = iter.pointNode;
    Node<T> *preNode = currentNode->prev;
    newNode->next = currentNode;
    newNode->prev = preNode;
    preNode->next = newNode;
    currentNode->prev = newNode;
    listSize++;
}

template<typename T>
void List<T>::erase(Iterator<T> iter)
{
    Node<T> *eraseNode = iter.pointNode;
    Node<T> *prevNode = eraseNode->prev;
    Node<T> *nextNode = eraseNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete eraseNode;
    listSize--;
}

template<typename T>
void List<T>::print() const
{
    for(Iterator<T> *iter = new Iterator<T>(headerNode->next);iter->pointNode!=trailerNode;iter++)
    {
        cout << iter->pointNode->memberElement << " ";
    }
    cout << "\n";
}

int main()
{
    int testCase;
    string s;
    cin >> testCase;
    cout << "qqq";
    List<int> l;
    cout << "qqq";
    Iterator<int> iter = l.begin();
    cout << "qqq";
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