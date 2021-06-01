#include<iostream>
#include<string>
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
  Node<T> *root;
public:
  BST():root(nullptr) {}
  void insert(T value, Node<T> *root = nullptr);
  void remove(T target);
  void print(Node<T> *target = nullptr);
  Node<T> *search(T targetValue, Node<T> *root = nullptr);
};
template<typename T>
void BST<T>::insert(T value, Node<T> *temp) {
  if(temp == nullptr) // 최초 호출시 작동
    temp = this->root;
  Node<T> *newNode = new Node<T>(value);
  if(this->root == nullptr) // BST가 비어있을때
    this->root = newNode;
  else if(temp->value > value && temp->left != nullptr) //값보다 작고 왼쪽자식이 있을경우
    insert(value, temp->left);
  else if(temp->value <= value && temp->right != nullptr) //값보다 크고 오른쪽 자식이 있을 경우
    insert(value, temp->right);
  else if(temp->value > value && temp->left == nullptr) { // 값보다 작고 왼쪽자식이 없을 경우
    temp->left = newNode;
    newNode->parent = temp;
  }
  else if(temp->value <= value && temp->right == nullptr) { //값보다 크고 오른쪽 자식이 없을 경우
    temp->right = newNode;
    newNode->parent = temp;
  }
}
template<typename T>
void BST<T>::remove(T target) {
  if(root == nullptr)
    return;
  Node<T> *tmp = search(target, root);
  if(tmp == nullptr) // 값을 찾을 수 없을때
    return;
  if(tmp == root && tmp->left == nullptr && tmp->right == nullptr){ // 값이 루트이며, 자식이 없을때
    root = nullptr;
    delete tmp;
  }
  else if(tmp == root && tmp->left != nullptr && tmp->right == nullptr) { // 값이 루트이며, 자식이 왼쪽만 있을때
    root = tmp->left;
    tmp->left->parent = nullptr;
    delete tmp;
  }
  else if(tmp == root && tmp->left == nullptr && tmp->right != nullptr) { // 값이 루트이며, 자식이 오른쪽만 있을때
    root = tmp->right;
    tmp->right->parent = nullptr;
    delete tmp;
  }
  else if (tmp->left == nullptr && tmp->right == nullptr) {
    if(tmp->parent->left == tmp)
      tmp->parent->left = nullptr;
    else if(tmp->parent->right == tmp)
      tmp->parent->right = nullptr;
    delete tmp;
  }
  else if(tmp->left == nullptr) { // 왼쪽 자식이 없을때
    tmp->right->parent = tmp->parent;
    if(tmp->parent->left == tmp)
      tmp->parent->left = tmp->right;
    else if(tmp->parent->right == tmp)
      tmp->parent->right = tmp->right;
    delete tmp;
  }
  else if(tmp->right == nullptr) { // 오른쪽 자식만 없을때
    tmp->left->parent = tmp->parent;
    if(tmp->parent->left == tmp)
      tmp->parent->left = tmp->left;
    else if(tmp->parent->right == tmp)
      tmp->parent->right = tmp->left;
    delete tmp;
  }
  else if(tmp->left != nullptr && tmp->right != nullptr) { //양쪽 자식 모두 있을때
    Node<T> *successor = tmp->right;
    while(successor->left!=nullptr)
      successor = successor->left;
    T tmpValue = successor->value;
    remove(tmpValue);
    tmp->value = tmpValue;
  }
}
template<typename T>
void BST<T>::print(Node<T> *target) {
  if(target == nullptr)
    target = root;
  if(root == nullptr)
    return;
  if(target->left != nullptr)
    print(target->left);
  if(target == root)
    cout << "r";
  cout << target->value << " ";
  if(target->right != nullptr)
    print(target->right);
  if(target == root)
    cout << "\n";
}
template<typename T>
Node<T> *BST<T>::search(T targetValue, Node<T> *temp) {
  if(temp == nullptr)
    temp = root;
  if(targetValue == temp->value)
    return temp;
  else if(targetValue < temp->value && temp->left != nullptr)
    return search(targetValue, temp->left);
  else if(targetValue > temp->value && temp->right != nullptr)
    return search(targetValue, temp->right);
  else
    return nullptr;
}
int main() {
  int testCase;
  string s;
  cout << "Insert Repeat Time : ";
  cin >> testCase;
  BST<int> b;
  for(int i=0; i<testCase; i++) {
    cin >> s;
    if(s=="insert") {
      int e;
      cin >> e;
      b.insert(e);
    } else if(s=="remove") {
      int e;
      cin >> e;
      b.remove(e);
    } else if(s=="print") {
      b.print();
    }
  }
}