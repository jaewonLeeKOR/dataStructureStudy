#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Sequence
{
    int sequenceSize;
    int frontIndex;
    int rearIndex;
    T *sequence;
    public:
    Sequence(int s=10):sequenceSize(s+1),frontIndex(0),rearIndex(0)
    {
        sequence = new T[sequenceSize];
        for(int i=0;i<sequenceSize;i++)
        {
            sequence[i] = (T)NULL;
        }
    }
    const int size() const {return (rearIndex - frontIndex + sequenceSize)%sequenceSize;}
    const bool empty() const {return rearIndex == frontIndex;}
    const bool full() const {return rearIndex == (frontIndex - 1 + sequenceSize) % sequenceSize;}
    const T front() const {return sequence[frontIndex];}
    const T rear() const {return sequence[rearIndex-1];}
    void insert(int targetIndex, int value);
    void insertFront(int value) {insert(frontIndex, value);}
    void insertRear(int value) {insert(rearIndex - 1, value);}
    T erase(int targetIndex=0);
    T eraseFront() {if(empty()){erase();}sequence[frontIndex] = (T)NULL; frontIndex = (frontIndex+1+sequenceSize)%sequenceSize;}
    T eraseRear() {if(empty()){erase();}rearIndex = (rearIndex-1+sequenceSize)%sequenceSize; sequence[rearIndex] = (T)NULL;}
    void clear();
    T at(int index) {return sequence[(frontIndex+index+sequenceSize)%sequenceSize];}
    T operator[](int index) const {return sequence[(frontIndex+index+sequenceSize)%sequenceSize];}
    void print() const;
    void printReverse() const;
};
template<typename T>
void Sequence<T>::insert(int targetIndex, int value)
{
    if(size() == sequenceSize-1)
    {
        cout << "Sequence is Full.\n";
        return ;
    }
    for(int i=rearIndex; i!=targetIndex; i--)
    {
        i = (i + sequenceSize) % sequenceSize;
        int prevIndex = (i-1 + sequenceSize) % sequenceSize;
        sequence[i] = sequence[prevIndex];
    }
    sequence[targetIndex] = value;
    rearIndex = (rearIndex + 1 + sequenceSize) % sequenceSize;
}
template<typename T>
T Sequence<T>::erase(int targetIndex)
{
    if(empty())
    {
        cout << "Sequence us Empty.\n";
        return (T)NULL;
    }
    for(int i=targetIndex; i!=rearIndex; i++)
    {
        i = (i + sequenceSize) % sequenceSize;
        int nextIndex = (i+1 +sequenceSize) % sequenceSize;
        sequence[i] = sequence[nextIndex];
    }
    rearIndex = (rearIndex-1 + sequenceSize) % sequenceSize;
}
template<typename T>
void Sequence<T>::clear()
{
    for(int i=frontIndex;i<rearIndex;i++)
        sequence[i] = (T)NULL;
    rearIndex = frontIndex;
}
template<typename T>
void Sequence<T>::print() const
{
    if(empty())
    {
        cout << "Sequence is Empty.\n";
        return;
    }
    for(int i=frontIndex;i!=rearIndex;i++)
    {
        i = (i+sequenceSize) % sequenceSize;
        cout << sequence[i] << " ";
    }
    cout << "\n";
}
template<typename T>
void Sequence<T>::printReverse() const
{
    for(int i=rearIndex;i!=frontIndex;i--)
    {
        i = (i + sequenceSize) % sequenceSize;
        int prevIndex = (i - 1 + sequenceSize) % sequenceSize;
        cout << sequence[prevIndex] << " ";
    }
    cout << "\n";
}
int main()
{
    cout << "Input testCase & sequence size : ";
    int testCase, size;
    string s;
    cin >> testCase >> size;
    Sequence<int> sq(size);
    for(int i=0;i<testCase;i++)
    {
        cin >> s;
        if(s=="size")
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
        else if(s=="full")
        {
            if(sq.full())
                cout << "Sequence is Full.\n";
            else
                cout << "Sequence is not Full.\n";
        }
        else if(s=="front")
        {
            cout << sq.front() << "\n";
        }
        else if(s=="rear")
        {
            cout << sq.rear() << "\n";
        }
        else if(s=="insert")
        {
            int index, data;
            cin >> index >> data;
            sq.insert(index, data);
        }
        else if(s=="insertFront")
        {
            int data;
            cin >>data;
            sq.insertFront(data);
        }
        else if(s=="insertRear")
        {
            int data;
            cin >> data;
            sq.insertRear(data);
        }
        else if(s=="erase")
        {
            int index;
            cin >> index;
            sq.erase(index);
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
            int index;
            cin>> index;
            cout << sq.at(index) << "\n";
        }
        else if(s=="[]")
        {
            int index;
            cin >> index;
            cout << sq[index] << "\n";
        }
        else if(s=="print")
        {
            sq.print();
        }
        else if(s=="printReverse")
        {
            sq.printReverse();
        }
    }
}