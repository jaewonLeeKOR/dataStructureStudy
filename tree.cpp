#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Tree{
    class Node{
    public:
        T m_elem;
        Node *parent;
        vector<Node*> children;
        Node(T e):m_elem(e),parent(nullptr) {}
    };
    int treeSize;
    vector<Node*> treeNodes;
public:
    Tree(T rootElement=1):treeSize(0)
    {
        Node *newNode = new Node(rootElement);
        treeNodes.push_back(newNode);
        treeSize++;
    }
    const int size() const {return treeSize;};
    const bool empty() const {return treeSize==0;};
    const int depth() const;
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