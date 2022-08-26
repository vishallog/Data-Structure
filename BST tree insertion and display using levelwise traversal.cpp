#include<iostream>
using namespace std;

int rear = -1;
int front = 0;
struct BSTtree *queue[10];;
    
void push(struct BSTtree *data)
{
    rear++;
    queue[rear] = data;
}
struct BSTtree* pop()
{
    struct BSTtree *s;
    s = queue[front];
    front++;
    return s;
}
struct BSTtree
{
    int data;
    struct BSTtree *left;
    struct BSTtree *right;
};
//create the tree.
struct BSTtree* createTree(struct BSTtree *root)
{
    if(!root)
    {
        struct BSTtree *t = new BSTtree;
        int data;
        cout<<"Enter the data for node"<<"---->>  ";
        cin>>data;
        cout<<endl;
        t->data = data;
        t->left = NULL;
        t->right = NULL;
        root = t;
        cout<<"Node insert Successfully!!"<<endl;
        return root;
    }
        return root;
    
}
struct BSTtree* insertNode(struct BSTtree *root)
{
    int data;
    struct BSTtree *n = new BSTtree;
    cout<<"Enter the data for node"<<"---->>  ";
    cin>>data;
    cout<<endl;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    struct BSTtree *par = root;
    while(par != NULL)
    {
        if(par->data>data)
        {
            if(par->left == NULL)
            {
                par->left = n;
                cout<<"Node insert Successfully!!"<<endl;
                return root;
            }
            par = par->left;
        }
        else if(par->data<data)
        {
            if(par->right == NULL)
            {
                par->right = n;
                cout<<"Node insert Successfully!!"<<endl;
                return root;
            }
            par = par->right;
        }
    }
    return root;
}

void levelOrder(struct BSTtree *root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<"---->>";
    push(root->left);
    push(root->right);
    while(rear != front)
    {
        levelOrder(pop());
    }
    return;
}

int main()
{
    int i = 0;
    struct BSTtree *root = NULL;
    root = createTree(root);
    root = insertNode(root);
    root = insertNode(root);
    root = insertNode(root);
    root = insertNode(root);
    root = insertNode(root);
    root = insertNode(root);
    cout<<"\n\nLevel wise traversal is:"<<endl;
    levelOrder(root);
    
    return 0;
}
