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
    int size;
    vector<Node*> treeNodes;
public:
    Tree(T rootElement=1):size(0)
    {
        Node *newNode = new Node(rootElement);
        treeNode.push_back(newNode);
        size++;
    }
    const int size() const;
    const bool empty() const;
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