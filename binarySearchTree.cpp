#include<iostream>
using namespace std;
template<typename T>
struct Node {
  T value;
  Node<T> *left;
  Node<T> *right;
  Node<T> *parent;
  Node():value(NULL),left(nullptr),right(nullptr),parent(nullptr) {}
  Node(T v):value(v),left(nullptr),right(nullptr),parent(nullptr) {}
};
template<typename T>
class BST {
  Node<T> root;
public:
  BST():root(nullptr) {}
  void insert(T value, Node<T> *root = nullptr);
  void remove(T target);
  void print();
};
template<typename T>
void BST<T>::insert(T value, Node<T> *root) {
  if(root == nullptr)
    root = this->root;
  Node<T> newNode = new Node<T>(value);
  if(root == nullptr)
    this->root = newNode;
  if(root->value > value && root->left != nullptr)
    return insert(value, root->left);
  else if(root->value <= value && root->right != nullptr)
    return insert(value, root->right);
  if(root->value > value && root->left == nullptr) {
    root->left = newNode;
    newNode->parent = root;
  }
  else if(root->value <= value && root->right == nullptr) {
    root->right = newNode;
    newNode->parent = root;
  }
}
template<typename T>
void BST<T>::remove(T target) {
  Node<T> *tmp = root;
  if(tmp == nullptr)
    return;
  while(tmp!=nullptr) {
    if(tmp->value == target)
      break;
    else if(tmp->value > target)
      tmp = tmp->left;
    else if(tmp->value < target)
      tmp = tmp->right;
  }
  if(tmp == nullptr) // 값을 찾을 수 없을때
    return;
  if(tmp == root && tmp->left == nullptr && tmp->right == nullptr) // 값이 루트이며, 자식이 없을때
    root = nullptr;
  else if(tmp == root && tmp->left != nullptr && tmp->right == nullptr) { // 값이 루트이며, 자식이 왼쪽만 있을때
    root = tmp->left;
    tmp->left->parent = nullptr;
  }
  else if(tmp == root && tmp->left == nullptr && tmp->right != nullptr) { // 값이 루트이며, 자식이 오른쪽만 있을때
    root = tmp->right;
    tmp->right->parent = nullptr;
  }
  else if(tmp->left == nullptr && tmp != root) { // 왼쪽 자식이 없을때
    tmp->right->parent = tmp->parent;
    if(tmp->parent->left == tmp)
      tmp->parent->left = tmp->right;
    else if(tmp->parent->right == tmp)
      tmp->parent->right = tmp->right;
  }
  else if(tmp->right == nullptr && tmp != root) { // 오른쪽 자식만 없을때
    tmp->left->parent = tmp->parent;
    if(tmp->parent->left == tmp)
      tmp->parent->left = tmp->left;
    else if(tmp->parent->right == tmp)
      tmp->parent->right = tmp->left;
  }
  else if(tmp->left != nullptr && tmp->right != nullptr) { //양쪽 자식 모두 있을때
    Node<T> *successor = tmp->right;
    while(successor->left!=nullptr)
      successor = successor->left;
    T tmpValue = successor->value;
    remove(tmpValue);
    tmp->value = tmpValue;
  }
  delete tmp;
}
int main() {}