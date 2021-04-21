#include<iostream>
#include<vector>
#include<string>
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
    void preOrderScan(int amount); //input amount of data and scan with element, depth data
    void postOrderScan(int amount); //input amount of data and scan with element, depth data
    void preOrderPrint(T targetElement) const;
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
        cout << "Error : Element Not Found.\n";
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
        cout << "Error : Element Not Found.\n";
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
        cout << "Error : Element Not Found.\n";
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
        cout << "Error : Element Not Found.\n";
        return false;
    }
    if(targetNode->children.size()!=0)
        return true;
    else
        return false;
}
template<typename T>
void Tree<T>::insert(T parentElement, T childElement)
{
    Node<T> *parentNode = nullptr;
    for(Node<T> *node : treeNodes)
    {
        if(node->element == parentElement)
        {
            parentNode = node;
            break;
        }
    }
    if(parentNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return ;
    }
    Node<T> *newNode = new Node<T>(childElement);
    newNode->parent = parentNode;
    parentNode->children.push_back(newNode);
    treeNodes.push_back(newNode);
    treeSize++;
    return;
}
template<typename T>
void Tree<T>::preOrderPrint(T targetElement) const
{
    Node<T> *targetNode = nullptr;
    for(Node<T> *node : treeNodes)
    {
        if(targetElement == node->element)
        {
            targetNode = node;
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return ;
    }
    cout << targetNode->element << " ";
    for(Node<T> node:targetNode->children)
        preOrderPrint(node->element);
    if(targetNode->element == treeNodes[0]->element)
        cout << "\n";
    return;
}
template<typename T>
void Tree<T>::postOrderPrint(T targetElement) const
{
    Node<T> *targetNode = nullptr;
    for(Node<T> *node:treeNodes)
    {
        if(targetElement == node->element)
        {
            targetNode = node;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return ;
    }
    for(Node<T> *node:targetNode->children)
        postOrderPrint(node->element);
    cout << targetNode->element << " ";
    if(targetNode == treeNodes[0])
        cout << "\n";
}
template<typename T>
void Tree<T>::erase(T targetElement)
{
    Node<T> *targetNode = nullptr;
    for(int i=0; i<treeNodes.size();i++)
    {
        if(targetElement == treeNodes[i]->element)
        {
            targetNode = treeNodes[i];
            treeNodes.erase(treeNodes.begin()+i);
            break;
        }
    }
    if(targetNode == nullptr)
    {
        cout << "Error : Element Not Found.\n";
        return ;
    }
    if(targetNode == treeNodes[0])
    {
        cout << "Error : Root Node Selected.\n";
        return ;
    }
    for(int i=0;i<targetNode->parent->children.size();i++)
    {
        if(targetNode->element == targetNode->parent->children[i])
        {
            targetNode->parent->children.erase(targetNode->parent->children.begin() + i);
            break;
        }
    }
    for(Node<T> *node : targetNode->children)
        targetNode->parent->children.push_back(node);
    delete targetNode;
    treeSize--;
    return;
}
template<typename T>
void Tree<T>::eraseAll()
{
    for(Node<T> *node : treeNodes[0]->children)
        erase(node->element);
}
template<typename T>
void Tree<T>::preOrderScan(int amount)
{
    vector<T> v_element;
    vector<int> v_depth;
    for(int i=0;i<amount;i++)
    {
        T dt;
        cin >> dt;
        v_element.push_back(dt);
    }
    for(int i=0;i<amount;i++)
    {
        int dt;
        cin >> dt;
        v_depth.push_back(dt);
    }
    for(int i=amount-2;i>=0; i--)
    {
        T element = v_element[i], parentElement;
        int depth = v_depth[i];
        for(int j=i; j<amount; j++)
        {
            if(v_depth[j]==depth-1)
            {
                parentElement = v_element[j];
                break;
            }
        }
        insert(parentElement, element);
    }
}
template<typename T>
void Tree<T>::postOrderScan(int amount)
{
    vector<T> v_element;
    vector<int> v_depth;
    for(int i=0;i<amount;i++)
    {
        T data;
        cin >> data;
        v_element.push_back(data);
    }
    for(int i=0;i<amount;i++)
    {
        int data;
        cin >> data;
        v_depth.push_back(data);
    }
    for(int i=1;i<amount;i++)
    {
        T element = v_element[i], parentElement;
        int depth = v_depth[i];
        for(int j=i;j>=0;j--)
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
int main()
{
    int testCase;
    string s;
    cin >> testCase;
    Tree<int> tree;
    for(int i=0;i<testCase; i++)
    {
        cin >> s;
        if(s=="size")
            cout << tree.size() << "\n";
        else if(s=="empty")
        {
            if(tree.empty())
                cout << "Tree is empty.\n";
            else
                cout << "Tree is not empty.\n";
        }
        else if(s=="isRoot")
        {
            int e;
            cin >> e;
            if(tree.isRoot(e))
                cout << e << " is Root Element.\n";
            else
                cout << e << " is not Root Element.\n";
        }
        else if(s=="depth")
        {
            int e;
            cin >> e;
            e = tree.depth(e);
            if(e != -1)
                cout << e << "\n";
        }
        else if(s=="height")
        {
            cout << "1.Tree's height 2.SubTree's height\n";
            int t;
            cin >> t;
            if(t==1)
                tree.height();
            else
            {
                cout << "Input SubTree's RootElement : ";
                int e;
                cin >> e;
                tree.height(e);
            }
        }
        else if(s=="isExternal")
        {
            int e;
            cin >> e;
            if(tree.isExternal(e))
                cout << e << " is external element.\n";
            else
            {
                cout << e << " is not external element.\n";
            }
        }
        else if(s=="isInternal")
        {
            int e;
            cin >> e;
            if(tree.isInternal(e))
                cout << e << " is internal element.\n";
            else
            {
                cout << e << " is not internal element.\n";
            }
        }
        else if(s=="insert")
        {
            int parent, child;
            cin >> parent >> child;
            tree.insert(parent, child);
        }
        else if(s=="preOrderScan")
        {
            int amount;
            cin >> amount;
            tree.preOrderScan(amount);
        }
        else if(s=="postOrderScan")
        {
            int amount;
            cin >> amount;
            tree.postOrderScan(amount);
        }
        else if(s=="preOrderPrint")
            tree.preOrderPrint();
        else if(s=="postOrderPrint")
            tree.postPrderPrint();
        else if(s=="erase")
        {
            int e;
            cin >> e;
            tree.erase(e);
        }
        else if(s=="eraseAll")
            tree.eraseAll();
        else if(s=="q")
            break;
    }
}