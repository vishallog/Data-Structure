#include<iostream>
using namespace std;

int rear = -1;
int front = 0;
struct tree *queue[10];
    
void push(struct tree *data)
{
    rear++;
    queue[rear] = data;
}
struct tree* pop()
{
    struct tree *s;
    s = queue[front];
    front++;
    return s;
}
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
//create the tree.
struct tree* createTree(struct tree *root)
{
    if(!root)
    {
        struct tree *t = new tree;
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
struct tree* insertLeft(struct tree *root,int c)
{

    struct tree *n = new tree;
    struct tree *n1 = n;
    int data;
    if(c>=1)
    {
        return NULL;
    }
    else
    {
        c++;
        cout<<"\n Enter the data for Root-> left node --->> ";
        cin>>data;
        n->data = data;
        n->left = insertLeft(n,c);
       
        n->right = insertLeft(n,c);
        return n;
            
    }
    root->left = n1;root->right = NULL;cout<<"Left Node insert Successfully!!"<<endl;
    return root;
}
struct tree* insertRight(struct tree *root,int c)
{
    struct tree *n = new tree;
    struct tree *n1 = n;
    int data;
    if(c>=1)
    {
        return NULL;
    }
    else
    {
        c++;
        cout<<"\n Enter the data for Root-> right node --->>  ";
        cin>>data;
        n->data = data;
        n->left = insertRight(n,c);
        n->right = insertRight(n,c);
        return n;
        
    }
    root->right = n1;cout<<"Left Node insert Successfully!!"<<endl;
    return root;
}    
struct tree* insertNode(struct tree *root)
{
    int c = -1;
    if(root)
    {
        int ch;
            cout<<"\nEnter chocice in which side you want to insert the nodes---->>>  ";
            cin>>ch;
            if(ch == 1)
            {
                root->left = insertLeft(root,c);
            }
            else if(ch == 2)
            {
                root->right = insertRight(root,c);
            }
        
        cout<<endl;
    cout<<endl;
        return root ;
        
    }
    return root;
}
void PreOrder(struct tree *root)
{
    if(root)
    {
        cout<<root->data<<"---->>";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void inOrder(struct tree *root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->data<<"---->>";
        inOrder(root->right);
    }
}

void PostOrder(struct tree *root)
{
    if(root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<"---->>";
    }
}
void levelOrder(struct tree *root)
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
    struct tree *root = NULL;
    root = createTree(root);
    while(i<=1)
    {
        root = insertNode(root);
        i++;
    }
    
    cout<<"\n\nPreorder traversal is:"<<endl;
    PreOrder(root);
    
    cout<<"\n\nInorder traversal is:"<<endl;
    inOrder(root);
    cout<<"\n\nPostorder traversal is:"<<endl;
    PostOrder(root);
    
    cout<<"\n\nLevel wise traversal is:"<<endl;
    levelOrder(root);
    
    return 0;
}

/*
OUPUT:

/tmp/NvpZMFqfqB.o
Enter the data for node---->>  1
Node insert Successfully!!

Enter chocice in which side you want to insert the nodes---->  1
Enter the data for Root-> left node --->> 2
Enter the data for Root-> left node --->> 4
Enter the data for Root-> left node --->> 5
Enter chocice in which side you want to insert the nodes---->  2
Enter the data for Root-> right node --->>  3
Enter the data for Root-> right node --->>  6
Enter the data for Root-> right node --->>  7
Preorder traversal is:
1---->>2---->>4---->>5---->>3---->>6---->>7---->>

Inorder traversal is:
4---->>2---->>5---->>1---->>6---->>3---->>7---->>

Postorder traversal is:
4---->>5---->>2---->>6---->>7---->>3---->>1---->>
*/
