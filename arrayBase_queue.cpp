#include<iostream>
using namespace std;

template<typename T>
class Queue
{
    int frontIndex;
    int rearIndex;
    int queueCapacity;
    T *queue;
public:
    Queue(int n):frontIndex(0),rearIndex(0),queueCapacity(n+1)
    {
        queue = new T[queueCapacity];
        for(int i=0;i<queueCapacity;i++)
            queue[i] = (T)NULL;
    }
    inline const T rear() const {return queue[rearIndex-1];}
    inline const int capacity() const {return queueCapacity-1;}
    inline const int size() const {return (rearIndex - frontIndex + queueCapacity) % queueCapacity;}
    inline const bool empty() const {return size()==0;}
    inline const bool full() const {return size()==capacity();}
    void enqueue(T);
    T dequeue();
    void print() const;
};

template<typename T>
void Queue<T>::enqueue(T e)
{
    if(full())
    {
        cout << "Queue is Full.\n";
        return ;
    }
    queue[rearIndex] = e;
    ++rearIndex %= queueCapacity;
}

template<typename T>
T Queue<T>::dequeue()
{
    if(empty())
    {
        cout << "Queue is Empty.\n";
        return (T)NULL;
    }
    T tmp = queue[frontIndex];
    queue[frontIndex] = (T)NULL;
    ++frontIndex %= queueCapacity;
    return tmp;
}

template<typename T>
void Queue<T>::print() const
{
    if(empty())
    {
        cout << "Queue is Empty.\n";
        return ;
    }
    int tmp = frontIndex;
    while(tmp!=rearIndex)
    {
        cout << queue[tmp] << " ";
        ++tmp %= queueCapacity;
    }
    cout << "\n";
}

int main()
{
    int testCase, size;
    cin >> testCase;
    cout << "queue size : ";
    cin >> size;
    Queue<int> queue(size);
    string s;
    for(int i=0;i<testCase;i++)
    {
        cin >> s;
        if(s=="size")
        {
            cout << "Size : " << queue.size() << "\n";
        }
        else if(s=="capacity")
        {
            cout << "Capacity : " << queue.capacity() << "\n";
        }
        else if(s=="empty")
        {
            if(queue.empty())
                cout << "Queue is empty!\n";
            else
                cout << "Queue is not empty\n";
        }
        else if(s=="enqueue")
        {
            int e;
            cin >> e;
            queue.enqueue(e);
        }
        else if(s=="dequeue")
        {
            if(queue.empty())
                queue.dequeue();
            else
                cout << queue.dequeue() << "\n";
        }
        else if(s=="rear")
        {
            if(queue.rear()==(int)NULL)
                cout << "Queue is empty.\n";
            else
                cout << queue.rear() << "\n";
        }
        else if(s=="print")
        {
            queue.print();
        }
        else if(s=="q")
        {
            break;
        }
    }
}