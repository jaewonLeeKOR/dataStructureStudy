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
    const bool empty() const;
    const T front() const;
    const T rear() const;
    void insert(int index, int value);
    void insertFront(int value);
    void insertRear(int value);
    T erase(int index);
    T eraseFront();
    T eraseRear();
    void clear();
    T at(int index);
    T operator[](int index) const;
    void print();
    void printReverase();
};