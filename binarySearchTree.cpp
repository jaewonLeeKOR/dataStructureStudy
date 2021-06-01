#include<iostream>
using namespace std;
template<typename T>
struct Node {
  T value;
  Node<T> *left;
  Node<T> *right;
  Node():value(NULL),left(nullptr),right(nullptr) {}
  Node(T v):value(v),left(nullptr),right(nullptr) {}
};
template<typename T>
class BST {
  Node<T> root;
public:
  BST() {
    root = new Node<T>();
  }
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
  if(root->value > value && root->left == nullptr)
    root->left = newNode;
  else if(root->value <= value && root->right == nullptr)
    root->right = newNode;
}
int main() {}