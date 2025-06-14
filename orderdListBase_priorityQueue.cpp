#include<iostream>
#include<string>
#define asc 1 //오름차순
#define desc -1 //내림차순
using namespace std;
template<typename T>
struct Entry {
  int key;
  T value;
  Entry *next;
  Entry *prev;
  Entry():key(0),value(""),next(nullptr),prev(nullptr) {}
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
  int priorityKey(); //우선순위 큐의 우선순위가 가장높은 entry의 key값을 리턴한다
  T priorityValue(); //우선순위 큐의 우선순위가 가장높은 entry의 value값을 리턴한다
  T rank(int rank); //우선순위 큐의 우선순위가 rank번째인 entry의 value를 리턴한다
  int size(); //우선순위 큐의 entry 갯수를 리턴한다.
  bool empty() { //우선순위 큐가 비어있는지 리턴한다.
    return size() == 0;
  }
  void print();
};
template<typename T>
void PriorityQueue<T>::insert(int key, T value) {
  Entry<T> *newEntry = new Entry<T>(key,value);
  Entry<T> *tmp=header->next;
  for(; tmp != trailer; tmp = tmp->next) {
    if(key * priority > tmp->key * priority)
      continue;
    if(key * priority <= tmp->key * priority)
      break;
  }
  tmp->prev->next = newEntry;
  newEntry->prev = tmp->prev;
  tmp->prev = newEntry;
  newEntry->next = tmp;
}
template<typename T>
T PriorityQueue<T>::removePriority() {
  T res = rank(1);
  if(size() == 0)
    return NULL;
  Entry<T> *tmp = header->next;
  header->next = tmp->next;
  header->next->prev = header;
  delete tmp;
  return res;
}
template<typename T>
int PriorityQueue<T>::priorityKey() {
  return header->next->key;
}
template<typename T>
T PriorityQueue<T>::priorityValue() {
  return header->next->value;
}
template<typename T>
T PriorityQueue<T>::rank(int rank) {
  Entry<T> *tmp = header;
  for(int i=0; i<rank; i++)
    tmp = tmp->next;
  return tmp->value;
}
template<typename T>
int PriorityQueue<T>::size() {
  int count = 0;
  for(Entry<T> *tmp = header->next; tmp != trailer; tmp = tmp->next)
    count++;
  return count;
}
template<typename T>
void PriorityQueue<T>::print() {
  for(Entry<T> *tmp = header->next; tmp != trailer; tmp=tmp->next)
    cout << "( " << tmp->key << " : " << tmp->value << " )\n";
}
int main() {
  string s;
  int testCase, pri;
  cout << "Insert Repeat time : ";
  cin >> testCase;
  cout << "Insert Priority (a,d) : ";
  cin >> s;
  if(s == "asc")
    pri = asc;
  else if(s == "desc")
    pri = desc;
  PriorityQueue<string> p(pri);
  for(int i=0; i<testCase; i++) {
    cin >> s;
    if(s=="insert") {
      int idx;
      string value;
      cin >> idx >> value;
      p.insert(idx, value);
    } else if(s=="removePriority") {
      cout << p.removePriority() << "\n";
    } else if(s=="priorityKey") {
      cout << p.priorityKey() << "\n";
    } else if(s=="priorityValue") {
      cout << p.priorityValue() << "\n";
    } else if(s=="rank") {
      int r;
      cin >> r;
      cout << p.rank(r) << "\n";
    } else if(s=="size") {
      cout << p.size() << "\n";
    } else if(s=="empty") {
      cout << p.empty() << "\n";
    } else if(s=="print") {
      p.print();
    }
  }
}