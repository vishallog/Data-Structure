// Circular Linked List Program.
#include<iostream>
using namespace std;
// create the structure node.
struct node
{
    int data;
    struct node *next;
};

//  to display list.
void display(struct node* last)
{
    if(last!= NULL)
    {
        struct node* t1 = NULL;
        struct node* t = last->next;
        struct node* l = last->next;
    
        do
        {
            t1 = l->next;
            cout<<l->data<<" --> ";
            l = t1;
        }while(l!=t);
        cout<<endl;
    }
    cout<<"List is empty\n";
    return;
}
//to add data into empty list.
struct node* addtoempty(struct node *last, int data)
{
    if(last == NULL)
    {
        struct node* newnode = new node;
        newnode->data = data;
        last = newnode;
        last->next = last;
        return last; 
    }
    cout<<"List is not empty.\n";
    return last;
}
// to add data at begining.
struct node* addAtBeg(struct node* last,int data)
{
    struct node* newnode = new node;
    struct node* l = last;
    newnode->data = data;
    newnode->next = last->next;
    last->next = newnode;
    return last;
}
// to add data at ending.
struct node* addLast(struct node* last,int data)
{
    struct node* t1 = NULL;
    struct node* newnode = new node;
    newnode->data = data;
    t1 = last->next;
    last->next = newnode;
    newnode->next = t1;
    last = newnode;
    return last;
}
// to add data after particular node.
struct node* addAfter(struct node* last,int data,int node_data1)
{
    struct node* newnode = new node;
    newnode->data = data;
    struct node* t1 = last->next;
    struct node* t2 = last->next;
    struct node* temp = NULL;
    do
    {
        if(t1->data == node_data1)
        {
            temp = t1->next;
            t1->next = newnode;
            newnode->next = temp;
            if(t1 == t2)
            {
                last = newnode;
            }
            return last;
        }
        t1 = t1->next;
        
    }while(t1!=t2);
    cout<<"No such data for Node is found in List.!!\n";
    return last;
}
// to delete the node->data.
struct node* del(struct node* last,int node_data1)
{
    struct node* d = last;
    struct node *t = NULL;
    if(last!=NULL)
    {
        if(d == last->next && d->data == node_data1)
        {
            t = last;
            last = NULL;
            free(t);
            return last;
        }
        if(last->next->data == node_data1)
        {
            struct node *t2 = NULL;
            t2 = last->next;
            last->next = t2->next;
            free(t2);
            return last;
        }
        struct node* d = last->next;
        do
        {
            if(d->next->data == node_data1)
            {
                if(node_data1 == last->data)
                {
                struct node *a1 = NULL;
                a1 = d->next;
                d->next=a1->next;
                free(a1);
                last = d;
                return last;
                }
                struct node *a = NULL;
                a = d->next;
                d->next=a->next;
                free(a);
                return last;
            }
            d = d->next;
        }while(d->next!=last->next);
        cout<<"You have entered wrong input node data\n";
        return last;
    }
    cout<<"List is empty\n";
    return last;
}
int main()
{
    int ch,data,data1;
    struct node *last=NULL;
    cout<<"------------>>>> Welcome! to Circular Linked list <<<<-------------\n";
    cout<<"1) Display the list\n";
    cout<<"2) Insert in Empty list\n";
    cout<<"3) Insert at Begining of list\n";
    cout<<"4) Insert at End of the list\n";
    cout<<"5) Insert after Node data in the list\n";
    cout<<"6) Delete the node in the  list\n";
    cout<<"7) Exit the list\n";
    while(1)
    {
        cout<<"Enter your choice"<<" ---->> ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1:
            {
                display(last);
                break;
            }
            case 2:
            {
                cout<<"Enter the data for the list"<<" ---->> ";
                cin>>data;
                cout<<endl;
                last = addtoempty(last,data);
                break;
            }
            case 3:
            {
                cout<<"Enter the data for the list"<<" ---->> ";
                cin>>data;
                cout<<endl;
                last = addAtBeg(last,data);
                break;
            }
            case 4:
            {
                cout<<"Enter the data for the list"<<" ---->> ";
                cin>>data;
                cout<<endl;
                last = addLast(last,data);
                break;
            }
            case 5:
            {
                
                cout<<"Enter the data after which you want to add the node"<<" ---->> ";
                cin>>data1;
                cout<<endl;
                cout<<"Enter the data for the list"<<" ---->> ";
                cin>>data;
                cout<<endl;
                last = addAfter(last,data,data1);
                break;
            }
            case 6:
            {
                
                cout<<"Enter the data for which you want to delete the node"<<" ---->> ";
                cin>>data1;
                cout<<endl;
                last = del(last,data1);
                break;
            }
            case 7:
            {
                exit(0);
            }
            default:
            {
                cout<<"Invalid choice!!\n";
                break;
            }
            
            
        }
    }
    return 0;
}

/*
*------------------------------------->>>> Output <<<<------------------------------------*
/tmp/LPPJUhczmg.o
------------>> Welcome! to Circular Linked list <<<<-------------
1) Display the list
2) Insert in Empty list
3) Insert at Begining of list
4) Insert at End of the list
5) Insert after Node data in the list
6) Delete the node in the  list
7) Exit the list
Enter your choice ---->> 1
List is empty
Enter your choice ---->> 2
Enter the data for the list ---->> 1
Enter your choice ---->> 6
Enter the data for which you want to delete the node ---->> 1
Enter your choice ---->> 1
List is empty
Enter your choice ---->> 2
Enter the data for the list ---->> 2
Enter your choice ---->> 3
Enter the data for the list ---->> 1
Enter your choice ---->> 4
Enter the data for the list ---->> 3
Enter your choice ---->> 1
1 --> 2 --> 3 --> 
List is empty
Enter your choice ---->> 76
Invalid choice!!
Enter your choice ---->> 6
Enter the data for which you want to delete the node ---->> 3
Enter your choice ---->> 4
Enter the data for the list ---->> 4
Enter your choice ---->> 5
Enter the data after which you want to add the node ---->> 2
Enter the data for the list ---->> 3
Enter your choice ---->> 1
1 --> 2 --> 3 --> 4 --> 
List is empty
Enter your choice ---->> 
*/
