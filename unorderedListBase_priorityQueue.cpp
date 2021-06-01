#include<iostream>
#define asc 1 // 오름차순
#define desc -1 // 내림차순
using namespace std;
template<typename T>
struct Node {
  T value;
  Node<T> *next;
  Node<T> *prev;
  Node():next(nullptr),prev(nullptr),value(NULL) {}
  Node(T v):next(nullptr),prev(nullptr),value(v) {}
};
template<typename T>
class PriorityQueue {
  Node<T> *header;
  Node<T> *trailer;
  int priority;
public:
  PriorityQueue(int p):priority(p) {
    header = new Node<T>();
    trailer = new Node<T>();
    header->next = trailer;
    trailer->prev = header;
  }
  int size();
  bool empty() {return size() == 0;}
  void print();
  void insert(T value);
  T priorityValue();
  T removePriority();
  T rank(int rank);
};
template<typename T>
int PriorityQueue<T>::size() {
  int count = 0;
  for(Node<T> *tmp = header->next; tmp != trailer; tmp = tmp->next)
    count++;
  return count;
}
template<typename T>
void PriorityQueue<T>::print() {
  for(Node<T> *tmp = header->next; tmp != trailer; tmp = tmp->next)
    cout << tmp->value << " ";
  cout << "\n";
}
template<typename T>
void PriorityQueue<T>::insert(T value) {
  Node<T> *newNode = new Node<T>(value);
  newNode->prev = trailer->prev;
  newNode->next = trailer;
  trailer->prev->next = newNode;
  trailer->prev = newNode;
}
template<typename T>
T PriorityQueue<T>::priorityValue() {
  int res = 200000000 * priority;
  for(Node<T> *tmp = header->next; tmp != trailer; tmp = tmp->next) {
    if(res * priority > tmp->value * priority)
      res = tmp->value;
  }
  return res;
}
template<typename T>
T PriorityQueue<T>::removePriority() {
  T p = priorityValue();
  Node<T> tmp = header->next;
  for(; tmp != trailer; tmp = tmp->next) {
    if(p == tmp->value)
      break;
  }
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  delete tmp;
}
template<typename T>
T PriorityQueue<T>::rank(int rank) {
  PriorityQueue<T> tmp = this;
  int count = rank-1;
  if(count > size())
    return (T)NULL;
  for(int i=0; i<count; i++)
    tmp.removePriority();
  cout << tmp.priorityValue();
}
int main() {}