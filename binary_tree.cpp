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
    int reeSize;
    vector<Node<T>*> treeNodes;
public:
    BinaryTree(T rootElement):reeSize(0)
    {
        Node<T> *newNode = new Node<T>(rootElement);
        treeNodes.push_back(newNode);
        reeSize++;
    }
    const int size() const;
    const bool empty() const;
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