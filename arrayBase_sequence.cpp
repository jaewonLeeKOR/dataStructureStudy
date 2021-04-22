#include<iostream>
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
    T operator[](int index) const;
    void print();
    void printReverase();
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
        return;
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
