#include<iostream>
using namespace std;
template<typename T>
struct Node {
  T value;
  Node<T> *next;
  Node<T> *prev;
  Node():value(NULL),next(nullptr),prev(nullptr) {}
  Node(T v):value(v),next(nullptr),prev(nullptr) {}
};
template<typename T>
class BST {
  Node<T> root;
public:
  BST() {
    root = new Node<T>();
  }
  void insert(T value);
  void remove(T target);
  void print();
};