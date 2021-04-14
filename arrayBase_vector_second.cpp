#include<iostream>
using namespace std;

template<typename T>
class Vector
{
    int vectorCapacity;
    int vectorSize;
    T *vector;
public:
    Vector(int n=0):vectorCapacity(n),vectorSize(0)
    {
        vector = new T[vectorCapacity];
        for(int i=0;i<vectorCapacity;i++)
            vector[i] = (T)NULL;
    }
    inline T& operator[](int i) {return vector[i];}
    inline const int size() const {return vectorSize;}
    inline const int capacity() const {return vectorCapacity;}
    inline const bool empty() const {return size()==0;}
    inline const T at(int i) const {return vector[i];}
    inline const T front() const {return vector[0]!=(T)NULL?(T)NULL:vector[0];}
    inline const T back() const {return empty()?(T)NULL:vector[vectorSize-1];}
    void clear();
    void insert(int idx, int elem);
    void insert(int idx, int num, int elem);
    void erase(int b, int e=(T)NULL);
    void reserve(int n);
    void resize(int n, int elem=(T)NULL);
};

template<typename T>
void Vector<T>::clear()
{
    for(int i=0;i<vectorSize;i++)
        vector[i] = (T)NULL;
    vectorSize = 0;
}

template<typename T>
void Vector<T>::insert(int idx, int elem)
{
    if(vectorCapacity<=vectorSize+1)
        reserve(vectorSize+1);
    for(int i=vectorSize-1;i>=idx;i--)
    {
        vector[i+1] = vector[i];
    }
    vector[idx] = elem;
    vectorSize++;
}

template<typename T>
void Vector<T>::insert(int idx, int num, int elem)
{
    if(vectorCapacity<=vectorSize+num)
        reserve(vectorSize+num);
    for(int i=vectorSize-1;i>=idx;i--)
        vector[i+num] = vector[i];
    for(int i=idx;i<idx+num;i++)
        vector[i] = elem;
    vectorSize += num;
}

template<typename T>
void Vector<T>::erase(int beginIdx, int endIdx)
{
    if(endIdx==(T)NULL)
        endIdx = beginIdx+1;
    for(int i=beginIdx;i<endIdx;i++)
        vector[i] = (T)NULL;
}

template<typename T>
void Vector<T>::reserve(int n)
{
    T *newVector = new T[n];
    for(int i=0;i<vectorSize;i++)
        newVector[i] = vector[i];
    T *tmp = vector;
    vector = newVector;
    delete vector;
    vectorCapacity = n;
}

template<typename T>
void Vector<T>::resize(int n, int elem)
{
    if(vectorCapacity<=n)
        reserve(n);
    for(int i=vectorSize;i<n;i++)
        vector[i] = elem;
    vectorSize = n;
}


int main() {}