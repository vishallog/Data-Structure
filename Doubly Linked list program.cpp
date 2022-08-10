#include<iostream>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void insertNode(struct node** s,int data)
{
    struct node* l = *s;
    struct node* newnode = new node;
    newnode->data = data;
    if((*s) == NULL)
    {
        newnode->prev = (*s);
        newnode->next = NULL;
        (*s) = newnode;
        cout<<"Node Inserted Succesfully."<<endl;
        return;
    }
    while(l->next!=NULL)
    {
        l = l->next;
    }
    newnode->prev = l->next;
    l->next = newnode;
    newnode->next = NULL;
    cout<<"Node Inserted Succesfully."<<endl;
    return;
}
void display(struct node** s)
{
    struct node *t=NULL;
    struct node *l = *s;
    if(l == NULL)
    {
        cout<<"Doubly Linked List is Empty!!."<<endl;
        return;
    }
    cout<<"###########---> Doubly Linked List <---#############"<<endl;
    while(l!=NULL)
    {
        t = l->next;
        cout<<l->data<<" --> ";
        l = t;
    }
    cout<<endl;
    return;
}
void reverse(struct node** s)
{
    struct node *t1=NULL;
    struct node *t2=NULL;
    struct node *l=(*s);
    if(l!=NULL)
    {
        while(l!=NULL)
        {
            t2 = l->next;
            l->prev = l->next;
            l->next = t1;
            t1 = l;
            l = t2;
        }
        (*s) = t1;
    }
    return;
}
int main()
{
    int ch,data;
    int i = 1;
    struct node *s = NULL;
    cout<<"1) Insert the node"<<endl;
    cout<<"2) Display the node"<<endl;
    cout<<"3) Reverse ther Doubly Linked list"<<endl;
    cout<<"4) Exit."<<endl;
    
    while(i=1)
    {
        cout<<"Enter your choice"<<" ---> ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter the value for node:"<<" --> ";
                cin>>data;
                cout<<endl;
                insertNode(&s,data);
                break;
            }
            case 2:
            {
                display(&s);
                break;
            }
            
            case 3:
            {
                reverse(&s);
                break;
            }
            case 4:
            {
                cout<<"Exited.."<<endl;
                i = 0;
                break;
            }
            default:
            {
                cout<<"Invalid choice"<<endl;
            }
        }
    }
    return 0;
}


/* 
-------------------------->>> OUTPUT <<<--------------------------------
/tmp/EmUZGmToxn.o
1) Insert the node
2) Display the node
3) Reverse ther Doubly Linked list
4) Exit.
Enter your choice ---> 1
Enter the value for node: --> 54
Node Inserted Succesfully.
Enter your choice ---> 1
Enter the value for node: --> 32
Node Inserted Succesfully.
Enter your choice ---> 1
Enter the value for node: --> 65
Node Inserted Succesfully.
Enter your choice ---> 2
###########---> Doubly Linked List <---#############
54 --> 32 --> 65 --> 
Enter your choice ---> 3
Enter your choice ---> 2
###########---> Doubly Linked List <---#############
65 --> 32 --> 54 --> 
Enter your choice ---> 
*/
