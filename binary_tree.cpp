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
    vector<Node<T>*> treeNode;
public:
    BinaryTree(T rootElement):treeSize(0)
    {
        Node<T> *newNode = new Node<T>(rootElement);
        treeNode.push_back(newNode);
        treeSize++;
    }
    const int size() const {return treeSize;}
    const bool empty() const {return treeSize == 0;}
    const int depth(T targetElement) const;
    const int height(T targetElement) const;
    bool isRoot(T targetElement) const {return targetElement==treeNode[0]->element;}
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
template<typename T>
const int BinaryTree<T>::depth(T targetElement) const
{
    Node<T> *targetNode = nullptr;
    for(int i=0; i<treeNode.size(); i++)
    {
        if(treeNode[i]->element == targetElement)
        {
            targetElement = treeNode[i];
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Error : Element NOt Found.\n";
        return -1;
    }
    int d = 0;
    if(targetNode->parent != nullptr)
        d = depth(targetNode->parent->element) + 1;
    return d;
}
template<typename T>
const int BinaryTree<T>::height(T targetElement) const
{
    Node<T> *targetNode = nullptr;
    for(int i=0; i<treeNode.size(); i++)
    {
        if(treeNode[i] == targetElement)
        {
            targetNode = treeNode[i];
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return -1;
    }
    int h = 0, left = 0, right = 0;
    if(targetNode->leftChild != nullptr)
        left = depth(targetNode->leftChild->element) + 1;
    if(targetNode->rightChild != nullptr)
        right = depth(targetNode->rightChild->element) + 1;
    h = left > right ? left : right;
    return h;
}
