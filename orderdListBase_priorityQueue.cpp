#include<iostream>
#define asc 1
#define desc -1
using namespace std;
template<typename T>
struct Entry {
  int key;
  T value;
  Entry *next;
  Entry *prev;
  Entry():key(0),value(NULL),next(nullptr),prev(nullptr) {}
  Entry(int k, T v):key(k),value(v),next(nullptr),prev(nullptr) {}
};
template<typename T>
class PriorityQueue {
  int priority;
  Entry<T> *header;
  Entry<T> *trailer;
public:
  PriorityQueue(int p):priority(p) {
    header = new Entry<T>();
    trailer = new Entry<T>();
    header->next = trailer;
    trailer->prev = header;
  }
  void insert(int key, T value); //key값과 value값을 가지는 entry를 우선순위 큐 내에 삽입한다
  T removePriority(); //우선순위 큐의 우선순위가 가장높은 entry의 value를 리턴하고 제거한다
  int priorityKey(); //우선순위 큐의 우선순위가 가정높은 entry의 key값을 리턴한다
  T priorityValue(); //우선순위 큐의 우선순위가 가정높은 entry의 value값을 리턴한다
  T rank(int rank); //우선순위 큐의 우선순위가 rank번째인 entry의 value를 리턴한다
  int size(); //우선순위 큐의 entry 갯수를 리턴한다.
  bool empty() { //우선순위 큐가 비어있는지 리턴한다.
    return size() == 0;
  }
};
template<typename T>
void PriorityQueue<T>::insert(int key, T value) {
  Entry<T> newEntry = new Entry<T>(key,value);
  Entry<T> tmp=header->next;
  for(; tmp != trailer; tmp = tmp->next) {
    if(key > tmp->key)
      continue;
    if(key <= tmp->key)
      break;
  }
  tmp->prev->next = newEntry;
  newEntry->prev = tmp->prev;
  tmp->prev = newEntry;
  newEntry->next = tmp;
}