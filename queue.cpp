#include<iostream>
#include<string>
using namespace std;

struct Node{
    int m_data;
    Node *next;
    Node(int data):m_data(data),next(nullptr){}
};

class Queue{
private:
    int maxIdx;
    Node *first;
    Node *last;
public:
    Queue():maxIdx(-1),first(nullptr),last(nullptr){}
    
    const bool empty() const;
    void push(int data);
    int popFront();
    void print() const;
    const int size() const;

};

const bool Queue::empty() const{
    if(maxIdx == -1)
        return true;
    return false;
}

void Queue::push(int data){
    Node *newNode = new Node(data);
    if(maxIdx == -1)
    {
        first = newNode;
        last = newNode;
        maxIdx++;
    }
    else
    {
        last->next = newNode;
        last = newNode;
        maxIdx++;
    }
}

int Queue::popFront(){
    if(empty())
    {
        return -1;
    }
    else
    {
        int answer = first->m_data;
        Node *tmp = first;
        first = first->next;
        free(tmp);
        maxIdx--;
        return answer;
    }    
}

void Queue::print() const{
    if(empty())
    {
        cout << "empty" << "\n";
    }
    else
    {
        Node *tmp = first;
        while(tmp->next != nullptr)
        {
            cout << tmp->m_data << " ";
            tmp = tmp->next;
        }
        cout << tmp->m_data << "\n";
    }
}

const int Queue::size() const{
    return maxIdx + 1;
}

int main(){
    int testCase;
    cin >> testCase;
    Queue q;
    for(int i = 0; i < testCase; i++)
    {
        string s;
        cin >> s;
        if(s == "Push")
        {
            int data;
            cin >> data;
            q.push(data);
            q.print();
        }
        else if(s == "Pop")
        {
            if(q.empty())
                cout << "empty" << "\n";
            else
                cout << q.popFront() << "\n";
        }
        else if(s == "Print")
        {
            q.print();
        }
        else if(s == "Size")
        {
            cout << q.size() << "\n";
        }
    }
}