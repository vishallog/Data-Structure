#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b)? a : b; 
}
int height(node *n)
{
    if(n == NULL)
        return 0;
    return n->height;
}
int balanceOfNode(node *n)
{
    if(n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}
node* newNode(int data)
{
    node *n = new node();
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    n->height = 1;
    return n;
}
node* leftRotate(node *y)
{
    node *x =y->right;
    node *t1 = x->left;
    
    x->left = y;
    y->right = t1;
    
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    return x;
}
node* rightRotate(node *x)
{
    node *y = x->left;
    node *t1 = y->right;
    
    y->right = x;
    x->left = t1;
    
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    return y;
}
node* insert(node *n,int data)
{
    if(n == NULL)
    {
        return newNode(data);
    }
    
    if(data < n->data)
    {
        n->left = insert(n->left,data);
    }
    else if(data > n->data)
    {
        n->right = insert(n->right,data);
    }
    else
    {
        return n;
    }
    
    
    
    
    
    n->height = 1 + max(height(n->left),height(n->right));
    
    
    
    int balance = balanceOfNode(n);
    // Right Right case.
    if(balance < -1 && data > n->right->data)
    {
        return leftRotate(n);
    }
    // Left Left case.
    if(balance > 1 && data < n->left->data)
    {
        return rightRotate(n);
    }
    
    //Right - Left case.
    if(balance < -1 && data < n->right->data)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    // Left - Right case.
    if(balance > 1 && data > n->left->data)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    
    return n;
    
}
void preOrder(node *n)
{
    if(n != NULL)
    {
        cout<<n->data<<" --->> ";
        preOrder(n->left);
        preOrder(n->right);
    }
}

int main()
{
    node *n = NULL;
    n = insert(n, 10);
    n = insert(n, 20);
    n = insert(n, 30);
    n = insert(n, 40);
    n = insert(n, 50);
    n = insert(n, 25);
    preOrder(n);
    return 0;
}
