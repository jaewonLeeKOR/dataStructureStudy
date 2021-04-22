#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class BinaryTree
{
    template<typename N>
    struct Node
    {
        N element;
        Node<N> *parent;
        Node<N> *leftChild;
        Node<N> *rightChild;
        Node(N e):element(e),parent(nullptr),leftChild(nullptr),rightChild(nullptr) {}
    };
    int treeSize;
    vector<Node<T>*> treeNodes;
public:
    BinaryTree(T rootElement):treeSize(0)
    {
        Node<T> *newNode = new Node<T>(rootElement);
        treeNodes.push_back(newNode);
        treeSize++;
    }
    const int size() const {return treeSize;}
    const bool empty() const {return treeSize == 0;}
    const int depth() const;
    const int height() const;
    bool isRoot() const;
    bool isExternal() const;
    bool isInternal() const;
    void insert(T parentElement, T childElement);
    void preOrderScan(int amount);
    void postOrderScan(int amount);
    void inOrderScan(int amount);
    void preOrderPrint(T targetElement);
    void postOrderPrint(T targetElement);
    void inOrderPrint(T targetElement);
    void erase(T targetElement);
    void eraseAll();
};