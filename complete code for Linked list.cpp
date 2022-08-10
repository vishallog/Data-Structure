#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void insertAtFirst(struct node** s,int new_data,int count)
{
    
    struct node* newnode = new node;
    newnode->data = new_data;
    if(*s==NULL)
    {
        cout<<*s<<endl;
        *s = newnode;
        newnode->next=NULL;
        cout<<*s<<endl;
        count++;
        return;
    }
    cout<<*s;
    newnode->next=*s;
    *s = newnode;
    count++;
    return;
}
void insertAfter(struct node* prev_node,int new_data,int count)
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
    count++;
    return;
}
void insertLast(struct node** s,int new_data,int count)
{
    struct node* newnode = new node;
    struct node *last = (*s);
    newnode->data = new_data;
    newnode->next = NULL;
    if((*s)==NULL)
    {
        cout<<last<<"----->"<<*s<<endl;
        (*s) = newnode;
        count++;
        return;
    }
    while(last->next!=NULL)
    {
        
        last = last->next;
       
    }
    cout<<last->next<<endl;
    last->next = newnode;
    cout<<last->next;
    count++;
    return;
}
void display(struct node** s,int count)
{
    struct node *last = (*s);
    struct node *last1 = (*s);
    if((*s) == NULL)
    {
        cout<<"Linked list is empty!!"<<endl;
        return;
    }
    else
    {
        int i=0;
        while(last->next!=NULL)
        {
            last=last->next;
            cout<<last->data<<"-->";
            i++;
        }
    }
    cout<<endl;
    
}
void deleteAfter(struct node* s)
{
    struct node *l=s;
    cout<<"Deleted node data is:"<<l->next->data<<endl;
    s->next = s->next->next;
    return;
}
void reverse(struct node **head_ref) {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
    return;
}
int  main()
{
    int ch,count=0;
    struct node* s = NULL;
    
    cout<<"1) Insert at First position:"<<endl;
    cout<<"2) Insert after the node:"<<endl;
    cout<<"3) Insert at Last:"<<endl;
    cout<<"4) Display the Linked List:"<<endl;
    cout<<"5) Delete the node after:"<<endl;
    cout<<"6) Reverse the Linked listL"<<endl;
    cout<<"7) Exit"<<endl;
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
                    insertAtFirst(&s,data,count);
                    break;
                }
                case 2:
                {
                    int data;
                    cout<<"Enter the data for new_node:"<<" --> "<<endl;
                    cin>>data;
                    insertAfter(s->next,data,count);
                    break;
                }
                case 3:
                {
                    int data;
                    cout<<"Enter the data for new_node:"<<" --> "<<endl;
                    cin>>data;
                    insertLast(&s,data,count);
                    break;
                }
                case 4:
                {
                    cout<<"************** Linked List **************:"<<endl;
                    display(&s,count);
                    break;
                }
                case 5:
                {
                    deleteAfter(s->next);
                    break;
                }
                case 6:
                {
                    reverse(&s);
                    break;
                }
                case 7:
                {
                    cout<<"Exited";
                    break;
                }
                default:
                {
                    cout<<"Invalid choice"<<endl;
                    
                }
            }        
        }while(ch!=7);    
    
    return 0;
}
/*
******************************* OUTPUT******************************************


/tmp/M5CPLhgljz.o
1) Insert at First position:
2) Insert after the node:
3) Insert at Last:
4) Display the Linked List:
5) Delete the node after:
6) Reverse the Linked listL
7) Exit
Enter your choice: 1
Enter the data for new_node: --> 
32
0
0x56322d0b86d0
Enter your choice: 3
Enter the data for new_node: --> 
43
0
0x56322d0b86f0Enter your choice: 3
Enter the data for new_node: --> 
65
0
0x56322d0b8710Enter your choice: 3
Enter the data for new_node: --> 
656
0
0x56322d0b8730Enter your choice: 4
************** Linked List **************:
43-->65-->656-->
Enter your choice: 6
Enter your choice: 4
************** Linked List **************:
65-->43-->32-->
Enter your choice: 

*/
