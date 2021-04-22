#include<iostream>
#include<vector>
#include<string>
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
            targetNode = treeNode[i];
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
        if(treeNode[i]->element == targetElement)
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
        else if(parentNode->leftChild != nullptr && parentNode->rightChild != nullptr)
        {
            cout << "Error : Child Node is Full.\n";
            return ;
        }
    }
    else if(reverse == -1)
    {
        if(parentNode->rightChild == nullptr)
            parentNode->rightChild = childNode;
        else if(parentNode->leftChild == nullptr)
            parentNode->leftChild = childNode;
        else if(parentNode->leftChild != nullptr && parentNode->rightChild != nullptr)
        {
            cout << "Error : Child Node is Full.\n";
            return ;
        }
    }
    treeNode.push_back(childNode);
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
        postOrderPrint(targetNode->leftChild->element);
    if(targetNode->rightChild != nullptr)
        postOrderPrint(targetNode->rightChild->element);
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
        tmp->parent = nullptr;
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
template<typename T>
void BinaryTree<T>::inOrderScan(int amount)
{
    vector<T> v_element;
    vector<int> v_depth;
    for(int i=0; i<amount; i++)
    {
        int e;
        cin >> e;
        v_element.push_back(e);
    }
    for(int i=0; i<amount; i++)
    {
        int e;
        cin >> e;
        v_depth.push_back(e);
    }
    int maxDepth = 0;
    for(int i=0;i<amount;i++)
        maxDepth = maxDepth > v_depth[i] ? maxDepth : v_depth[i];
    for(int i=0; i<maxDepth; i++)
    {
        vector<int> index;
        for(int j=0;j<amount;j++) // 해당 높이 인덱스 구하기
        {
            if(v_depth[j] == i)
                index.push_back(j);
        }
        for(int j=0; j<index.size(); j++) // 해당 높이 인덱스 순회
        {
            int leftMax=-1, rightMax=amount;
            for(int k=index[j]; k>=0; k--) // 왼쪽 상한값 구하기
            {
                if(v_depth[k] == i-1)
                {
                    leftMax = k;
                    break;
                }
            }
            for(int k=index[j]; k<amount; k++) // 오른쪽 상한값 구하기
            {
                if(v_depth[k] == i-1)
                {
                    rightMax = k;
                    break;
                }
            }
            for(int k=index[j]; k>leftMax; k--) // 왼쪽 자식 구하기
            {
                if(v_depth[k] == i+1)
                {
                    insert(v_element[index[j]], v_element[k]);
                    break;
                }
            }
            for(int k=index[j]; k<rightMax; k++) // 오른쪽 자식 구하기
            {
                if(v_depth[k] == i+1)
                {
                    insert(v_element[index[j]], v_element[k]);
                    break;
                }
            }
        }
    }
}
int main()
{
    int testCase;
    string s;
    cin >> testCase;
    BinaryTree<int> b(1);
    for(int i=0; i<testCase; i++)
    {
        cin >> s;
        if(s=="size")
        {
            cout << b.size() << "\n";
        }
        else if(s=="empty")
        {
            cout << b.empty() << "\n";
        }
        else if(s=="depth")
        {
            int e;
            cin >> e;
            cout << b.depth(e) << "\n";
        }
        else if(s=="height")
        {
            int e;
            cin >> e;
            cout << b.height(e) << "\n";
        }
        else if(s=="isRoot")
        {
            int e;
            cin >> e;
            cout << b.isRoot(e) << "\n";
        }
        else if(s=="isExternal")
        {
            int e;
            cin >> e;
            cout << b.isExternal(e) << "\n";
        }
        else if(s=="isInternal")
        {
            int e;
            cin >> e;
            cout << b.isInternal(e) << "\n";
        }
        else if(s=="insert")
        {
            int p,c;
            cin >> p >> c;
            b.insert(p,c);
        }
        else if(s=="preOrderScan")
        {
            int a;
            cin >> a;
            b.preOrderScan(a);
        }
        else if(s=="postOrderScan")
        {
            int a;
            cin >> a;
            b.postOrderScan(a);
        }
        else if(s=="inOrderScan")
        {
            int a;
            cin >> a;
            b.inOrderScan(a);
        }
        else if(s=="preOrderPrint")
        {
            int e;
            cin >> e;
            b.preOrderPrint(e);
            cout << "\n";
        }
        else if(s=="postOrderPrint")
        {
            int e;
            cin >> e;
            b.postOrderPrint(e);
            cout << "\n";
        }
        else if(s=="inOrderPrint")
        {
            int e;
            cin >> e;
            b.inOrderPrint(e);
            cout << "\n";
        }
        else if(s=="eraseAll")
        {
            b.eraseAll();
        }
        else if(s=="q")
            break;
    }
}