#include<iostream>
#include<string>
#define asc 1 // 오름차순
#define desc -1 // 내림차순
using namespace std;
template<typename T>
struct Node {
  T value;
  Node<T> *next;
  Node<T> *prev;
  Node():next(nullptr),prev(nullptr),value((T)NULL) {}
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
  int idx = 0, s = size();
  T *tmp = new T[s];
  for(Node<T> *temp = header->next; temp != trailer; temp = temp->next) {
    tmp[idx++] = temp->value; // 배열로 복사
  }
  for(int i=0; i<s; i++) {
    int p = tmp[i]; // 정렬되지 않은 값중 가장 앞의 값
    idx = i; // 정렬되지않은 값중 가장 앞의 인덱스
    for(int j=i; j<s; j++) {
      if(tmp[j] * priority < p * priority){ // 정렬되지 않은 값중 우선순위가 높은 값을 지정
        idx = j;
        p = tmp[j];
      }
    }
    int t = tmp[idx];
    tmp[idx] = tmp[i];
    tmp[i] = t; // swap
  }
  for(int i = 0; i<s; i++)
    cout << tmp[i] << " "; // 출력
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
  Node<T> *tmp = header->next;
  for(; tmp != trailer; tmp = tmp->next) {
    if(p == tmp->value)
      break;
  }
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  delete tmp;
  return p;
}
template<typename T>
T PriorityQueue<T>::rank(int rank) {
  int idx = 0, s = size();
  T *tmp = new T[s];
  for(Node<T> *temp = header->next; temp != trailer; temp = temp->next)
    tmp[idx++] = temp->value;
  for(int i=0; i<rank; i++) {
    int p = tmp[i];
    idx = i;
    for(int j=i; j<s; j++) {
      if(tmp[j] * priority < p * priority) {
        idx = j;
        p = tmp[j];
      }
    }
    int t = tmp[idx];
    tmp[idx] = tmp[i];
    tmp[i] = t;
  }
  return tmp[rank-1];
}
int main() {
  int testCase, pri;
  string s;
  cout << "Input Repeat Time : ";
  cin >> testCase;
  cout << "Input Priority (desc , asc) : ";
  cin >> s;
  if(s=="asc")
    pri = asc;
  else if(s=="desc")
    pri = desc;
  PriorityQueue<int> p(pri);
  for(int i=0;i<testCase;i++)
  {
    cin >> s;
    if(s=="size") {
      cout << p.size() << "\n";
    } else if(s=="empty") {
      cout << p.empty() << "\n";
    } else if(s=="print") {
      p.print();
    } else if(s=="insert") {
      int e;
      cin >> e;
      p.insert(e);
    } else if(s=="priorityValue") {
      cout << p.priorityValue() << "\n";
    } else if(s=="removePriority") {
      cout << p.removePriority() << "\n";
    } else if(s=="rank") {
      int e;
      cin >> e;
      cout << p.rank(e) << "\n";
    }
  }
}