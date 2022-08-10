#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void insertAtFirst(struct node** s,int new_data)
{
    struct node* newnode = new node;
    newnode->data = new_data;
    newnode->next=(*s);
    (*s) = newnode;
}
void insertAfter(struct node* prev_node,int new_data)
{
    if(prev_node == NULL)
    {
        cout<<"Warning!! the given previous node is required, cannot be NULL"<<endl;
        return;
    }
    cout<<prev_node->data<<endl;
    struct node* newnode = new node;
    newnode->data = new_data;
    newnode->next = prev_node->next;
    prev_node->next = newnode;
    return;
}
void insertLast(struct node** s,int new_data)
{
    struct node* newnode = new node;
    struct node *last = (*s);
    newnode->data = new_data;
    newnode->next = NULL;
    if((*s)==NULL)
    {
        cout<<last<<"----->"<<*s<<endl;
        (*s) = newnode;
        return;
    }
    while(last->next!=NULL)
    {
        
        last = last->next;
       
    }
    cout<<last->next<<endl;
    last->next = newnode;
    cout<<last->next;
    return;
}
void display(struct node** s)
{
    struct node *last = (*s);
    if((*s) == NULL)
    {
        cout<<"Linked list is empty!!"<<endl;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
        cout<<last->data<<"-->";
    }
    
    cout<<endl;
    
}
int  main()
{
    int ch;
    struct node* s = NULL;
    
    cout<<"1) Insert at First position:"<<endl;
    cout<<"2) Insert after the node:"<<endl;
    cout<<"3) Insert at Last:"<<endl;
    cout<<"4) Display the Linked List:"<<endl;
    cout<<"4) Exit"<<endl;
        do
        {
            cout<<"Enter your choice:"<<" ";
            cin>>ch;
            cout<<endl;
            switch(ch)
            {
        
                case 1:
                {
                    int data;
                    cout<<"Enter the data for new_node:"<<" --> "<<endl;
                    cin>>data;
                    insertAtFirst(&s,data);
                    break;
                }
                case 2:
                {
                    int data;
                    cout<<"Enter the data for new_node:"<<" --> "<<endl;
                    cin>>data;
                    insertAfter(s->next,data);
                    break;
                }
                case 3:
                {
                    int data;
                    cout<<"Enter the data for new_node:"<<" --> "<<endl;
                    cin>>data;
                    insertLast(&s,data);
                    break;
                }
                case 4:
                {
                    cout<<"************** Linked List **************:"<<endl;
                    display(&s);
                    break;
                }
                case 5:
                {
                    cout<<"Exited";
                    break;
                }
                default:
                {
                    cout<<"Invalid choice"<<endl;
                    
                }
            }        
        }while(ch!=5);    
    
    return 0;
}
/*
********************** OUTPUT ******************************

1) Insert at First position:
2) Insert after the node:
3) Insert at Last:
4) Display the Linked List:
4) Exit
Enter your choice: 1
Enter the data for new_node: --> 
34
Enter your choice: 1
Enter the data for new_node: --> 
65
Enter your choice: 4
************** Linked List **************:
34-->
Enter your choice: 1
Enter the data for new_node: --> 
65
Enter your choice: 4
************** Linked List **************:
65-->34-->
Enter your choice: 3
Enter the data for new_node: --> 
76
0
0x561bb78bb730Enter your choice: 4
************** Linked List **************:
65-->34-->76-->
Enter your choice: 2
Enter the data for new_node: --> 
45
65
Enter your choice: 4
************** Linked List **************:
65-->45-->34-->76-->
Enter your choice: 5
Exited
*/
