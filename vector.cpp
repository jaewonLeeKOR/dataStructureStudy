#include<iostream>
using namespace std;

struct Node{
    int m_data;
    int index;
    Node(int data, int idx):m_data(data),index(idx){}
};

class Vector{
private:
    int m_size; //원소 갯수
    int m_capacity; //할당된 메모리 공간
    int *vector;
public:
    Vector(int n = 0, int v = 0):m_size(n){
        int binary_number = 2;
        while(true)
        {
            if(n / binary_number == 0)
                break;
            else
                binary_number *= 2;
        }
        m_capacity = binary_number;   
        int *vector = new int[m_capacity];
        for(int i = 0; i < n; i++)
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
    int* insert(int idx, int data, int n = 1);
    void erase(int *iter);
    void erase(int *start, int *end);
    const bool empty() const;
};

void Vector::assign(int n, int data){
    if(m_size + n > m_capacity)
        reserve(m_size+n); // m_size + n 이 m_capacity를 넘어가 index error 가 날 경우를 제거
    for(int i = 0; i < n; i++)
    {
        vector[m_size+i] = data;
    }
    m_size += n;
}

int Vector::at(int idx) const{
    return vector[idx - 1];
}

int Vector::front() const{
    return vector[0];
}

int Vector::back() const{
    return vector[m_size-1];
}

void Vector::clear(){
    for(int i = m_size; i >= 0; i--)
        vector[i] = 0;
    m_size = 0;
}

void Vector::push_back(int data){
    if(m_size + 1 > m_capacity)
        reserve(m_size+1);
    vector[m_size] = data;
    m_size++;
}

void Vector::pop_back(){
    vector[m_size-1] = 0;
    m_size--;
}

int* Vector::begin() const{
    return &vector[0];
}

int* Vector::end() const{
    return &vector[m_size-1];
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
        if(i < m_size)
        {
            tmp[i] = vector[i];
        }
        else
        {
            tmp[i] = 0;
        }
    }
    m_capacity = n;
    vector = tmp;
    free(tmp);
}

void Vector::resize(int n, int v){
    if(n > m_capacity)
        reserve(n);
    for(int i = m_size - 1; i < n; i++)
    {
        vector[i] = v;
    }
    m_size = n;
}

int Vector::size() const{
    return m_size;
}

int Vector::capacity() const{
    return m_capacity;
}

int* Vector::insert(int idx, int data, int n){
    if(m_size + n > m_capacity)
        reserve(m_size + n);
    for(int i = n - 1; i >= 0; i--)
    {
        vector[idx - 1 + n + i] = vector[idx - 1 + i];
    }
    for(int i = 0; i<n; i++)
    {
        vector[idx - 1 + i] = data;
    }
    m_size += n;
    return &vector[idx];
}

void Vector::erase(int *iter){
    bool appear = false;
    for(int i = 0; i < m_size; i++)
    {
        if(iter == &vector[i])
        {
            appear = true;
        }
        else if(appear)
        {
            vector[i - 1] = vector[i];
            vector[i] = 0;
        }
    }
    m_size--;
}

void Vector::erase(int *start, int *end){
    int startIdx = -1, endIdx = -1;
    for(int i = 0; i < m_size; i++)
    {
        if(start == &vector[i])
            startIdx = i;
        if(end == &vector[i])
            endIdx = i;
        else if(startIdx != -1 && endIdx != -1)
        {
            vector[i - (endIdx - startIdx)] = vector[i];
            vector[i] = 0;
        }
    }
    m_size -= endIdx - startIdx;
}

const bool Vector::empty() const{
    if(m_size == 0)
        return true;
    return false;
}