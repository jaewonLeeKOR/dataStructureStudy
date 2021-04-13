#include<iostream>
#include<string>
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
    void print() const;
};

template<typename T>
void LinkedList<T>::insertHead(T element)
{
    Node<T> *newNode = new Node<T>(element);
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

template<typename T>
void LinkedList<T>::insertTail(T element)
{
    Node<T> *newNode = new Node<T>(element);
    if(empty())
    {
        headNode = newNode;
        tailNode = newNode;
    }
    else
    {
        tailNode->next = newNode;
        tailNode = newNode;
    }
    listSize++;
}

template<typename T>
void LinkedList<T>::removeHead()
{
    if(empty())
    {
        cout << "empty\n";
        return;
    }
    else if(size() == 1)
    {
        Node<T> *tmp = headNode;
        delete tmp;
        headNode = nullptr;
        tailNode = nullptr;
    }
    else
    {
        Node<T> *tmp = headNode;
        headNode = tmp->next;
        delete tmp;
    }
    listSize--;
}

template<typename T>
void LinkedList<T>::removeTail()
{
    if(empty())
    {
        cout << "empty\n";
        return;
    }
    else if(size() == 1)
    {
        Node<T> *tmp = tailNode;
        delete tmp;
        headNode = nullptr;
        tailNode = nullptr;
    }
    else
    {
        Node<T> *tmp = headNode;
        while(tmp->next != tailNode)
            tmp = tmp->next;
        tailNode = tmp;
        tmp = tmp->next;
        tailNode->next = nullptr;
        delete tmp;
    }
    listSize--;
}

template<typename T>
T LinkedList<T>::showHead() const
{
    if(empty())
        return (T)NULL;
    return headNode->memberElement;
}

template<typename T>
T LinkedList<T>::showTail() const
{
    if(empty())
        return (T)NULL;
    return tailNode->memberElement;
}

template<typename T>
void LinkedList<T>::print() const
{
    if(empty())
    {
        cout << "list is empty.\n";
        return;
    }
    Node<T> *tmp = headNode;
    while(tmp != nullptr)
    {
        cout << tmp->memberElement << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

int main(){
    int textCase;
    cin >> textCase;
    string s;
    LinkedList<int> list;
    for(int i=0;i<textCase;i++)
    {
        cin >> s;
        if(s=="size")
        {
            cout << "size : " << list.size() << "\n";
        }
        else if(s=="empty")
        {
            if(list.empty())
                cout << "linkedList is empty\n";
            else
                cout << "linkedList is not empty\n";
        }
        else if(s=="insertHead")
        {
            int e;
            cin >> e;
            list.insertHead(e);
        }
        else if(s=="insertTail")
        {
            int e;
            cin >> e;
            list.insertTail(e);
        }
        else if(s=="removeHead")
        {
            list.removeHead();
        }
        else if(s=="removeTail")
        {
            list.removeTail();
        }
        else if(s=="showHead")
        {
            cout << "Head : " << list.showHead() << "\n";
        }
        else if(s=="showTail")
        {
            cout << "Tail : " << list.showTail() << "\n";
        }
        else if(s=="print")
        {
            list.print();
        }
        else if(s=="q")
        {
            break;
        }
    }
}