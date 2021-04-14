#include<iostream>
using namespace std;

template<typename T>class Queue;

template<typename T>
class Node{
    int memberElement;
    Node<T> *next;
    Node<T>(T element):memberElement(element),next(nullptr) {}
    friend class Queue<T>;
};

template<typename T>
class Queue{
    int queueSize;
    Node<T> *frontNode;
    Node<T> *rearNode;
public:
    Queue<T>():queueSize(0),frontNode(nullptr),rearNode(nullptr) {}
    inline const int size() const {return queueSize;}
    inline const bool empty() const {return queueSize==0;}
    inline const T front() const {return frontNode->memberElement;}
    void push(T);
    T pop();
    void print();
};

template<typename T>
void Queue<T>::push(T e)
{
    Node<T> *newNode = new Node<T>(e);
    if(empty())
        rearNode = newNode;
    newNode->next = frontNode;
    frontNode = newNode;
    queueSize++;
}

template<typename T>
T Queue<T>::pop()
{
    Node<T> *tmp = frontNode;
    while(tmp->next != rearNode)
        tmp=tmp->next;
    rearNode = tmp;
    tmp = tmp->next;
    rearNode->next = nullptr;
    T answer = tmp->memberElement;
    delete tmp;
    queueSize--;
    return answer;
}

template<typename T>
void Queue<T>::print()
{
    if(empty())
    {
        cout << "Queue is empty!\n";
        return;
    }
    Node<T> *tmp = frontNode;
    while(tmp!=nullptr)
    {
        cout << tmp->memberElement << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

int main() {}