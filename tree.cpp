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
    const int depth(T targetElement) const;
    const int height(T targetElement=-1) const;
    bool isRoot(T targetElement) const {return targetElement==treeNodes[0]->element;};
    bool isExternal(T targetElement) const;
    bool isInternal(T targetElement) const;
    void insert(T parentElement, T childElement);
    void preOrderScan(T targetElement);
    void postOrderScan(T targetElement);
    void preOrederPrint(T targetElement) const;
    void postOrderPrint(T targetElement) const;
    void erase(T targetElement);
    void eraseAll();
};
template<typename T>
const int Tree<T>::depth(T targetElement) const
{
    Node<T> *targetNode = nullptr;
    for(Node<T> *node:treeNodes)
    {
        if(targetElement == node->element)
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
template<typename T>
const int Tree<T>::height(T targetElement) const
{
    if(targetElement==-1)
        targetElement = (treeNodes[0]->element);
    Node<T> *targetNode = nullptr;
    for(Node<T> *node: treeNodes)
    {
        if(targetElement == node->element)
        {
            targetNode = node;
            break;
        }
    }
    if(targetNode==nullptr)
    {
        cout << "Element Not Found.\n";
        return -1;
    }
    int d=0;
    for(Node<T> *node:targetNode->children)
    {
        int h=height(node->element)+1;
        if(d<h)
            d = h;
    }
    return d;
}
template<typename T>
bool Tree<T>::isExternal(T targetElement) const
{
    Node<T> *targetNode = nullptr;
    for(Node<T> *node: treeNodes)
    {
        if(targetElement == node->element)
        {
            targetNode = node;
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Element Not Found.\n";
        return false;
    }
    if(targetNode->children.size() == 0)
        return true;
    else
        return false;
}
template<typename T>
bool Tree<T>::isInternal(T targetElement) const
{
    Node<T> *targetNode = nullptr;
    for(Node<T> *node : treeNodes)
    {
        if(targetElement==node->element)
        {
            targetNode = node;
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Element Not Found.\n";
        return false;
    }
    if(targetNode->children.size()!=0)
        return true;
    else
        return false;
}