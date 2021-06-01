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
  bool empty();
  void print();
  void insert(T value);
  T priorityValue();
  T removePriority();
};
template<typename T>
int PriorityQueue<T>::size() {
  int count = 0;
  for(Node<T> *tmp = header->next; tmp != trailer; tmp = tmp->next)
    count++;
  return count;
}
int main() {}