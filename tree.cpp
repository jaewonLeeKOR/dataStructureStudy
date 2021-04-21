#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Tree{
    template<typename N>
    class Node{
    public:
        N element;
        Node *parent;
        vector<Node*> children;
        Node(N e):element(e),parent(nullptr) {}
    };
    int treeSize;
    vector<Node<T>*> treeNodes;
public:
    Tree(T rootElement=1):treeSize(0)
    {
        Node<T> *newNode = new Node<T>(rootElement);
        treeNodes.push_back(newNode);
        treeSize++;
    }
    const int size() const {return treeSize;};
    const bool empty() const {return treeSize==0;};
    const int depth(T target) const;
    const int height() const;
    bool isRoot();
    bool isExternal();
    bool isInternal();
    void insert(T parentElement, T childElement);
    void preOrderScan(T target);
    void postOrderScan(T target);
    void preOrederPrint(T target) const;
    void postOrderPrint(T target) const;
    void erase(T target);
    void eraseAll();
};
template<typename T>
const int Tree<T>::depth(T target) const
{
    Node<T> *targetNode = nullptr;
    for(Node<T> *node:treeNodes)
    {
        if(target == node->element)
        {
            targetNode = node;
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Element Not Found.\n";
        return -1;
    }
    int h=0;
    if(targetNode->parent != nullptr)
        h+=depth(targetNode->parent->element)+1;
    return h;
}