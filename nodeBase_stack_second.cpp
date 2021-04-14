//update template availability
#include<iostream>
#include<string>
using namespace std;

template<typename T>class Stack;

template<typename T>
class Node{
    T memberElement;
    Node<T> *next;
    Node(T e):memberElement(e),next(nullptr) {}
    friend class Stack<T>;
};

template<typename T>
class Stack{
    int stackSize;
    Node<T> *topNode;
public:
    Stack():stackSize(0),topNode(nullptr) {}
    inline const int size() const {return stackSize;}
    inline const bool empty() const {return stackSize==0;}
    T top() const {return topNode->memberElement;}
    void push(T);
    T pop();
    void print() const;
};

template<typename T>
void Stack<T>::push(T element)
{
    Node<T> *newNode = new Node<T>(element);
    newNode->next = topNode;
    topNode = newNode;
    stackSize++;
}

template<typename T>
T Stack<T>::pop()
{
    if(empty())
    {
        cout << "Stack is empty!\n";
        return (T)NULL;
    }
    Node<T> *tmp = topNode;
    topNode = tmp->next;
    T answer = tmp->memberElement;
    delete tmp;
    stackSize--;
    return answer;
}

template<typename T>
void Stack<T>::print() const
{
    if(empty())
    {
        cout << "Stack is empty!\n";
        return;
    }
    Node<T> *tmp = topNode;
    while(tmp != nullptr)
    {
        cout << tmp->memberElement << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

int main(){
    int testCase;
    cin >> testCase;
    string s;
    Stack<int> stack;
    for(int i=0;i<testCase;i++)
    {
        cin >> s;
        if(s=="size")
        {
            cout << "Size : " << stack.size() << "\n";
        }
        else if(s=="empty")
        {
            if(stack.empty())
                cout << "Stack is empty!\n";
            else
                cout << "Stack is not empty\n";
        }
        else if(s=="push")
        {
            int e;
            cin >> e;
            stack.push(e);
        }
        else if(s=="pop")
        {
            if(stack.empty())
                stack.pop();
            else
                cout << stack.pop() << "\n";
        }
        else if(s=="print")
        {
            stack.print();
        }
        else if(s=="q")
        {
            break;
        }
    }
}