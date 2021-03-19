#indlude<iostream>
using namespace std;

struct Node{
    int m_data;
    int index;
    Node(int data, int idx):m_data(data),index(idx){}
};

class Vector{
private:
    int size; //원소 갯수
    int capacity; //할당된 메모리 공간
    int *vector;
public:
    Vector(int l = 0, int v = 0):size(l){
        int *vector = new int[capacity];
        for(int i = 0; i < l; i++)
        {
            vector[i] = v;
        }
    }

    void assign(int n, int data);
    int at(int idx) const;
    //v[idx];
    int front() const;
    int back() const;
    void clear();
    void push_back(int data);
    void pop_back();
    int* begin() const;
    int* end() const;
    //rbegin();
    //rend();
    void reserve(int n);
    void resize(int n, int v = 0);
    int size() const;
    int capacity() const;
    //v2.swap(v1);
    int* insert(int idx, int data, int n = 0);
    void erase(int *iter);
    void erase(int *start, int *erase);
};

void Vector::assign(int n, int data){
    if(size + n > capacity)
        reserve(size+n); // size + n 이 capacity를 넘어가 index error 가 날 경우를 제거
    for(int i = 0; i < n; i++)
    {
        vector[size+i] = data;
    }
    size += n;
}

int Vector::at(int idx) const{
    return vector[idx];
}

int Vector::front() const{
    return vector[0];
}

int Vector::back() const{
    return vector[size-1];
}

void Vector::clear(){
    for(int i = size; i >= 0; i--)
        vector[i] = 0;
    size = 0;
}

void Vector::push_back(int data){
    if(size + 1 > capacity)
        reserve(size+1);
    vector[size] = data;
    size++;
}

void Vector::pop_back(){
    vector[size-1] = 0;
    size--;
}

int* Vector::begin() const{
    return &vector[0];
}

int* Vector::end() const{
    return &vector[size-1];
}

void Vector::reserve(int n){
    int binary_number = 2;
    while(true)
    {
        if(n / binary_number == 0)
            break;
        else
            binary_number *= 2;
    }
    n = binary_number;
    int *tmp = new int[n]; 
    for(int i = 0; i < n; i++)
    {
        if(i < size)
        {
            tmp[i] = vector[i];
        }
        else
        {
            tmp[i] = 0;
        }
    }
    capacity = n;
    vector = tmp;
    free(tmp);
}

void Vector::resize(int n, int v = 0)
{
    reserve(n);
    int *tmp = new int[n];
    for(int i = 0; i < n; i++)
    {
        tmp[i] = v;
    }
    size = n;
}

int size() const{
    return size;
}

int Vector::capacity() const{
    return capacity;
}