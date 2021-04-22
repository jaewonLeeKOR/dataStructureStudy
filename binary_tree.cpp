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
    bool isExternal(T targetElement) const;
    bool isInternal(T targetElement) const;
    void insert(T parentElement, T childElement, int reverse=1);
    void preOrderScan(int amount);
    void postOrderScan(int amount);
    void inOrderScan(int amount);
    void preOrderPrint(T targetElement);
    void postOrderPrint(T targetElement);
    void inOrderPrint(T targetElement);
    // void erase(T targetElement);
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
template<typename T>
bool BinaryTree<T>::isExternal(T targetElement) const
{
    Node<T> *targetNode = nullptr;
    for(int i=0; i<treeNode.size(); i++)
    {
        if(targetElement == treeNode[i]->element)
        {
            targetNode = treeNode[i];
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return false;
    }
    return targetNode->leftChild == nullptr && targetNode->rightChild == nullptr;
}
template<typename T>
bool BinaryTree<T>::isInternal(T targetElement) const
{
    Node<T> *targetNode = nullptr;
    for(int i=0; i<treeNode.size(); i++)
    {
        if(targetElement == treeNode[i]->element)
        {
            targetNode = treeNode[i];
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return false;
    }
    return targetNode->leftChild != nullptr || targetNode->rightChild != nullptr;
}
template<typename T>
void BinaryTree<T>::insert(T parentElement, T childElement, int reverse)
{
    Node<T> *parentNode = nullptr;
    for(int i=0; i<treeNode.size(); i++)
    {
        if(parentElement == treeNode[i]->element)
        {
            parentNode = treeNode[i];
            break;
        }
    }
    if(parentNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return;
    }
    Node<T> *childNode = new Node<T>(childElement);
    if(reverse == 1)
    {
        if(parentNode->leftChild == nullptr)
            parentNode->leftChild = childNode;
        else if(parentNode->rightChild == nullptr)
            parentNode->rightChild = childNode;
    }
    else if(reverse == -1)
    {
        if(parentNode->rightChild == nullptr)
            parentNode->rightChild = childNode;
        else if(parentNode->leftChild == nullptr)
            parentNode->leftChild = childNode;
    }
    if(parentNode->leftChild != nullptr && parentNode->rightChild != nullptr)
    {
        cout << "Error : Child Node is Full.\n";
        return ;
    }
    childNode->parent = parentNode;
    treeSize++;
    return ;
}
template<typename T>
void BinaryTree<T>::preOrderPrint(T targetElement)
{
    Node<T> *targetNode = nullptr;
    for(int i=0;i<treeNode.size(); i++)
    {
        if(targetElement == treeNode[i])
        {
            targetNode = treeNode[i];
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return ;
    }
    cout << targetNode->element << " ";
    if(targetNode->leftChild != nullptr)
        preOrderPrint(targetNode->leftChild->element);
    if(targetNode->rightChild != nullptr)
        preOrderPrint(targetNode->rightChild->element);
    return ;
}
template<typename T>
void BinaryTree<T>::postOrderPrint(T targetElement)
{
    Node<T> *targetNode = nullptr;
    for(int i=0;i<treeNode.size();i++)
    {
        if(targetElement == treeNode[i]->element)
        {
            targetNode = treeNode[i];
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return ;
    }
    if(targetNode->leftChild != nullptr)
        preOrderPrint(targetNode->leftChild->element);
    if(targetNode->rightChild != nullptr)
        preOrderPrint(targetNode->rightChild->element);
    cout << targetNode->element << " ";
    return ;
}
template<typename T>
void BinaryTree<T>::inOrderPrint(T targetElement)
{
    Node<T> *targetNode = nullptr;
    for(int i=0;i<treeNode.size();i++)
    {
        if(targetElement == treeNode[i]->element)
        {
            targetNode = treeNode[i];
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return ;
    }
    if(targetNode->leftChild != nullptr)
        inOrderPrint(targetNode->leftChild->element);
    cout << targetNode->element << " ";
    if(targetNode->rightChild != nullptr)
        inOrderPrint(targetNode->rightChild->element);
    return ;
}
// template<typename T>
// void BinaryTree<T>::erase(T targetElement)
// {
//     Node<T> *targetNode = nullptr;
//     for(int i=0; i<treeNode.size(); i++)
//     {
//         if(targetElement == treeNode[i]->element)
//         {
//             targetNode = treeNode[i];
//             break;
//         }
//     }
//     if(targetNode == nullptr)
//     {
//         cout << "Error : Element Not Found.\n";
//         return ;
//     }
// }
template<typename T>
void BinaryTree<T>::eraseAll()
{
    for(int i=treeNode.size()-1; i>0; i--)
    {
        Node<T> *tmp = treeNode[i];
        tmp->parentNode = nullptr;
        tmp->rightChild = nullptr;
        tmp->leftChild = nullptr;
        delete tmp;
        treeSize--;
    }
    return;
}
template<typename T>
void BinaryTree<T>::preOrderScan(int amount)
{
    vector<T> v_element;
    vector<int> v_depth;
    for(int i=0;i<amount; i++)
    {
        int t;
        cin >> t;
        v_element.push_back(t);
    }
    for(int i=0;i<amount; i++)
    {
        int t;
        cin >> t;
        v_depth.push_back(t);
    }
    for(int i=1; i<amount; i++)
    {
        T element = v_element[i], parentElement;
        int depth = v_depth[i];
        for(int j=i; j>=0; j--)
        {
            if(v_depth[j] == depth-1)
            {
                parentElement = v_element[j];
                break;
            }
        }
        insert(parentElement, element);
    }
}
template<typename T>
void BinaryTree<T>::postOrderScan(int amount)
{
    vector<T> v_element;
    vector<int> v_depth;
    for(int i=0;i<amount; i++)
    {
        int t;
        cin >> t;
        v_element.push_back(t);
    }
    for(int i=0;i<amount; i++)
    {
        int t;
        cin >> t;
        v_depth.push_back(t);
    }
    for(int i=amount-2; i>=0; i--)
    {
        T element = v_element[i], parentElement;
        int depth = v_depth[i];
        for(int j=i; j<amount; j++)
        {
            if(v_depth[j] == depth-1)
            {
                parentElement = v_element[j];
                break;
            }
        }
        insert(parentElement, element, -1);
    }
}
