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
    void erase(int idx, int num=(T)NULL);
    void reserve(int n);
    void resize(int n, int elem=(T)NULL);
};

int main() {}