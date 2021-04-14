#include<iostream>
#include<string>
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
    void print() const;
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

template<typename T>
void Vector<T>::print() const
{
    for(int i=0;i<vectorSize;i++)
    {
        cout << vector[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int testCase, size;
    cin >> testCase;
    cout << "Input vector Size : ";
    cin >> size;
    Vector<int> vec(size);
    string s;
    for(int j=0;j<testCase;j++)
    {
        cin >> s;
        if(s=="[]")
        {
            int i;
            cin >> i;
            cout << "Vector[i] : " << vec[i] << "\n";
        }
        else if(s=="size")
        {
            cout << "Size : " << vec.size() << "\n";
        }
        else if(s=="capacity")
        {
            cout << "Capacity : " << vec.capacity() << "\n";
        }
        else if(s=="empty")
        {
            if(vec.empty())
                cout << "Vector is empty,\n";
            else
                cout << "Vector is not empty.\n";
        }
        else if(s=="at")
        {
            int i;
            cin >> i;
            cout << vec.at(i) << "\n";
        }
        else if(s=="front")
        {
            cout << vec.front() << "\n";
        }
        else if(s=="back")
        {
            cout << vec.back() << "\n";
        }
        else if(s=="clear")
        {
            vec.clear();
        }
        else if(s=="insert")
        {
            int num;
            cout << "1.insert(idx, elem) 2.insert(idx, num, elem)\n";
            cin >> num;
            if(num==1)
            {
                int i,e;
                cin >> i >> e;
                vec.insert(i,e);
            }
            else
            {
                int i,n,e;
                cin >> i >> n >> e;
                vec.insert(i,n,e);
            }
        }
        else if(s=="erase")
        {
            int num;
            cout << "1.erase(idx) 2.erase(beginIdx, endIdx)\n";
            cin >> num;
            if(num==1)
            {
                int i;
                cin >> i;
                vec.erase(i);
            }
            else
            {
                int b,e;
                cin >> b >> e;
                vec.erase(b,e);
            }
        }
        else if(s=="reserve")
        {
            int n;
            cin >> n;
            vec.reserve(n);
        }
        else if(s=="resize")
        {
            int num;
            cout << "1.resize(n) 2.resize(n,e)\n";
            cin >> num;
            if(num==1)
            {
                int n;
                cin >> n;
                vec.resize(n);
            }
            else
            {
                int n, e;
                cin >> n >> e;
                vec.resize(n,e);
            }
        }
        else if("print")
        {
            vec.print();
        }
    }
}