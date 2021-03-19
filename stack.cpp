#include<iostream>
#include<string>
using namespace std;

struct Node{
    int m_data;
    Node *next;
    Node(int data):m_data(data){}
};

class Stack{
private:
    int maxIdx;
    Node *topNode;
public:
    Stack():maxIdx(-1),topNode(nullptr){}

    const bool empty() const;
    void push(int data);
    int pop();
    int top() const;
    int size() const;
    const void print() const;
};

const bool Stack::empty() const{
    if(maxIdx == -1)
        return true;
    return false;
}

void Stack::push(int data){
    Node *newNode = new Node(data);
    if(empty())
    {
        topNode = newNode;
        maxIdx++;
    }
    else
    {    
        Node *tmp = topNode;
        newNode->next = tmp;
        topNode = newNode;
        maxIdx++;
    }
}

int Stack::pop(){
    Node *preTmp = topNode;
    Node *tmp = topNode->next;
    topNode = tmp;
    int answer = preTmp->m_data;
    free(preTmp);
    maxIdx--;
    return answer;
}

int Stack::top() const{
    return topNode->m_data;
}

int Stack::size() const{
    return maxIdx+1;
}

const void Stack::print() const{
    if(maxIdx == -1)
    {
        cout << "empty" << "\n";
    }
    else
    {    
        Node *tmp = topNode;
        while(tmp->next != nullptr)
        {
            cout << tmp->m_data << " ";
            tmp = tmp->next;
        }
        cout << tmp->m_data << "\n";
    }
}

int main(){
    int testCase;
    cin >> testCase;
    Stack stack;
    for(int i = 0; i < testCase; i++)
    {
        string s;
        cin >> s;
        if( s == "Push")
        {
            int data;
            cin >> data;
            stack.push(data);
            stack.print();
        }
        else if( s == "Pop")
        {
            if(stack.empty())
                cout << "empty" << "\n";
            else
                cout << stack.pop() << "\n";
        }
        else if( s == "Top")
        {
            if(stack.empty())
                cout << "empty" << "\n";
            else
                cout << stack.top() << "\n";
        }
        else if( s == "Size")
        {
            cout << stack.size() << "\n";
        }
        else if( s == "Print")
        {
            stack.print();
        }
    }
}