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
    T erase(int index);
    T eraseFront();
    T eraseRear();
    void clear();
    T at(int index);
    T operator[](int index) const;
    void print();
    void printReverase();
};
template<typename T>
void Sequence<T>::insert(int targetIndex, int value)
{
    if(size() == sequenceSize-1)
    {
        cout << "Sequnce is Full.\n";
        return ;
    }
    for(int i=rearIndex; i!=targetIndex; i--)
    {
        if(i<0)
            i = (i + sequenceSize) % sequenceSize;
        sequence[i] = sequence[i-1];
    }
    sequence[targetIndex] = value;
    rearIndex = (rearIndex + 1) % sequenceSize;
}