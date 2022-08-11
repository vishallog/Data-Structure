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
void afterNode(struct node** s,int data,int data1)
{
    struct node* newnode = new node;
    struct node *t = (*s);
    struct node *t2 = NULL;
    newnode->data = data;
    while(t!=NULL)
    {
        if(t->data == data1)
        {
            newnode->prev = t;
            newnode->next = t->next;
            t->next->prev = newnode;
            t->next = newnode;
            return;
        }
        t2 = t->next;
        t=t2;
    }
    cout<<"You have entered the wrong element\n";
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
    int ch,data,data1;
    int i = 1;
    struct node *s = NULL;
    cout<<"1) Insert the newnode"<<endl;
    cout<<"2) Insert the newnode after the node-> data"<<endl;
    cout<<"3) Display the node"<<endl;
    cout<<"4) Reverse ther Doubly Linked list"<<endl;
    cout<<"5) Exit."<<endl;
    
    while(i=1)
    {
        cout<<"Enter your choice"<<" ---> ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                for(int i = 0;i<5;i++)
                {
                    cout<<"Enter the value for node:"<<" --> ";
                    cin>>data;
                    cout<<endl;
                    insertNode(&s,data);
                }
                break;
            }
            case 2:
            {
                cout<<"Enter the data value of node after which you want to add newnode:"<<" --> ";
                cin>>data1;
                cout<<"Enter the value for node:"<<" --> ";
                cin>>data;
                cout<<endl;
                afterNode(&s,data,data1);
                break;
                
            }
            case 3:
            {
                display(&s);
                break;
            }
            
            case 4:
            {
                reverse(&s);
                break;
            }
            case 5:
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
/tmp/LPPJUhczmg.o
1) Insert the newnode
2) Insert the newnode after the node-> data
3) Display the node
4) Reverse ther Doubly Linked list
5) Exit.
Enter your choice ---> 1
Enter the value for node: --> 12
Node Inserted Succesfully.
Enter the value for node: --> 23
Node Inserted Succesfully.
Enter the value for node: --> 34
Node Inserted Succesfully.
Enter the value for node: --> 45
Node Inserted Succesfully.
Enter the value for node: --> 56
Node Inserted Succesfully.
Enter your choice ---> 67
Invalid choice
Enter your choice ---> 2
Enter the data value of node after which you want to add newnode: --> 45
Enter the value for node: --> 50
Enter your choice ---> 3
###########---> Doubly Linked List <---#############
12 --> 23 --> 34 --> 45 --> 50 --> 56 --> 
Enter your choice ---> 4
Enter your choice ---> 3
###########---> Doubly Linked List <---#############
56 --> 50 --> 45 --> 34 --> 23 --> 12 --> 
Enter your choice ---> 5
Exited..
Enter your choice ---> */
