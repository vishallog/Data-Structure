// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int stack[10], n=10, top=-1;
void push(int value)
{
    if(top>=n-1)
        cout<<"Warning: stack is overflowing!!"<<endl;
    else
    {
        top++;
        stack[top]=value;
    }
}
void pop()
{
    if(top<=-1)
        cout<<"Warning: Stack is Underflowing!!"<<endl;
    else
    {
        cout<<"Poped element is: "<< stack[top] << endl;   
        top--;
    }
    
}
void display()
{
    if(top<=-1)
        cout<<"Warning: Stack is empty!!"<<endl;
    else
    {
        cout<<"Elements of stack:"<<endl;
        for(int i=top;i>=0;i--)
        {
            cout<<stack[i]<<" ";
            cout<<endl; 
        }
    }
}

int main() {
    // driver code..
    int ch, value;
    cout<<"1) Push is Stack:"<<endl;
    cout<<"2) POP in Stack:"<<endl;
    cout<<"3) Display the Stack:"<<endl;
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
                cout<<"Enter element to Push"<<" "<<endl;
                cin>>value;
                push(value);
                break;
            }
            
            case 2:
            {
                pop();
                break;
            }
            
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                cout<<"Exit"<<endl;
                break;
            }
            default:
            {
                cout<<"Warning: Invalid Choice";
                
            }
            
                
        }
        
    }while(ch!=4);
    return 0;
    

}


/* OUTPUT:
1) Push is Stack:
2) POP in Stack:
3) Display the Stack:
4) Exit
Enter your choice: 1
Enter element to Push 
23
Enter your choice: 1
Enter element to Push 
23
Enter your choice: 3
Elements of stack:
23 
23 
Enter your choice: 2
Poped element is: 23
Enter your choice: 2
Poped element is: 23
Enter your choice: 3
Warning: Stack is empty!!
Enter your choice: 2
Warning: Stack is Underflowing!!
Enter your choice: 
*/
