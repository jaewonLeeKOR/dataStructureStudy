#include<iostream>
using namespace std;

class Array {
private:
    int size;
    int *arr;
    class cell {
    private:
        int value;
        int index;
    };
public:
    Array(int arrSize,int defaultValue = 0){
        this->size = arrSize;
        this->arr = new int[size];
        for(int i = 0; i < size; i++)
        {
            arr[i] = defaultValue;
        }
    }
    void add(int idx, int val);
    void remove(int idx);
    void set(int idx, int val);
}