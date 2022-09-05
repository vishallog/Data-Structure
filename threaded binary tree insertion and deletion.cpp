#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    bool lthread;
    bool rthread;
};

node* insert(node *root,int data)
{
    node *ptr = root;
    node *par = NULL;
    while(ptr != NULL)
    {
        if((ptr->data) == data)
        {
            cout<<"\n Duplicate data."<<endl;
            return root;
        }
        par = ptr;
        if(data < (ptr->data))
        {
            if(ptr->lthread == false)
            {
                ptr = ptr->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(ptr->rthread == false)
            {
                ptr = ptr->right;
            }
            else
            {
                break;
            }
        }
    }
    
    
    node *tmp = new node;
    tmp->data = data;
    tmp->lthread = true;
    tmp->rthread = true;
    
    if(par == NULL)
    {
        root = tmp;
        tmp->left = NULL;
        tmp->right = NULL;
        //cout<<tmp->data<<endl;
    }
    else if((ptr->data) > data)
    {
        tmp->left = par->left;
        tmp->right = par;
        par->lthread = false;
        par->left = tmp;
        //cout<<tmp->data<<endl;
    }
    else
    {
        tmp->left = par;
        tmp ->right = par->right;
        par->rthread = false;
        par->right = tmp;   
        //cout<<tmp->data<<endl;
    }
    
    return root;
}
struct node* inordersuccessor(node* ptr)
{
    //cout<<ptr->data<<" -->> ";
    if(ptr->rthread == true)
    {
        return ptr->right;
    }
    
    ptr = ptr->right;
    while(ptr->lthread == false)
    {
        ptr = ptr->left;
    }
    return ptr;
}
void inorder(node *root)
{
    
    struct node *ptr = root;
    if(root == NULL)
    {
        cout<<"\n Threaded Tree is empty!!."<<endl;
    }
    while(ptr->lthread == false)
    {
        ptr = ptr->left;
    }
    
    while(ptr != NULL)
    {
        cout<<ptr->data<<" -->> ";
        ptr = inordersuccessor(ptr);
    }
}
void deletion(node *root,int data)
{
    node *ptr = root; 
    node *par = NULL;
    int found = 0;
    while(ptr != NULL)
    {
        if((ptr->data) == data)
        {
            found = 1;
            break;
        }
        par = ptr;
        if(data < (ptr->data))
        {
            if(ptr->lthread == false)
            {
                ptr = ptr->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(ptr->rthread == false)
            {
                ptr = ptr->right;
            }
            else
            {
                break;
            }
        }
    }
    
    if(found == 0)
    {
        cout<<"\n No key found";
    }
    if(found == 1)
    {
        if(ptr->lthread == true && ptr->rthread == true)
        {
            if(par == NULL)
                root = NULL;
            else if(ptr == par->left)
            {
                par->left = ptr->left;
                par->lthread = true;
            }
            else
            {
                par->rthread = true;
                par->right = ptr->right;
            }
        }
        if(ptr->lthread == false && ptr->rthread == true || ptr->lthread == true && ptr->rthread == false)
        {
            node *child;
            if(ptr->lthread == false)
            {
                child = ptr->left;
            }
            else
            {
                child = ptr->right;
            }
            
            if(par==NULL)
                root = NULL;
            else if(ptr == par->left)
            {
                par->left = child;
            }
            else
                par->right = child;
            
            
            node *p = ptr->left;
            node *s = ptr->right;
            
            
            if(ptr->lthread == false)
            {
                p->right = s;
            }
            else{
                if(ptr->rthread == false)
                {
                    s->left = p;
                }
            }
            
        }
        if(ptr->lthread == false && ptr->rthread == false)
        {
             //cout<<endl<<ptr->data<<endl;
            node *succ = ptr->right;
            // cout<<endl<<succ->data<<endl;
            node *parsucc = ptr;
            while(succ->lthread != true)
            {
                parsucc = succ;
                succ = succ->left;
            }
            //cout<<endl<<ptr->data<<endl;
            ptr->data = succ->data;
            //cout<<endl<<ptr->data<<endl;
            //cout<<"\n parsucc"<<parsucc->data<<endl;
            if(succ->lthread == true && succ->rthread == true)
            {

                if(succ == parsucc->left)
                {
                    //cout<<endl<<succ->data<<endl;
                    //cout<<endl<<parsucc->data<<endl;
                    parsucc->left = succ->left;
                    parsucc->lthread = true;
                    //cout<<endl<<succ->data<<endl;
                    //cout<<endl<<parsucc->data<<endl;
                    //cout<<endl<<parsucc->left<<endl;
                    //cout<<endl<<ptr->rthread<<endl;
                    //cout<<endl<<parsucc->left<<endl;
                }
                else
                {
                    parsucc->rthread = true;
                    parsucc->right = succ->right;
                }
                
            }
            
        }
    }
    
}
int main()
{
    node *root=NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);
    inorder(root);
    deletion(root,16);
    cout<<endl;
    inorder(root);
    return 0;
}
