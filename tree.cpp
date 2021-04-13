#include<iostream>
#include<queue>
using namespace std;

class Tree{
    class Node{
    public:
        int m_elem;
        Node *parent;
        queue<Node*> children;
        Node(int e):m_elem(e) {}
    }
    int height;
    int size;
    Node *root;
public:
    class Iterator{
    public:
        Node *node;
        Iterator(Node *n = nullptr):node(n) {}
    }
    Tree():height(0),size(0),root(nullptr) {}
    int size();
    bool empty();
    Iteraotr& root();
    bool isRoot(Iterator iter);
    bool isExternal(Iterator iter);
    bool isInternal(Iterator iter);
    int depth(Iterator iter);
    int height();
    Iterator& parent(Iterator iter);
    Tree& descendant(Iterator iter);
}