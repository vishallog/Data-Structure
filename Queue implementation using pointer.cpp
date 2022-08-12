// Queue implementation program.
#include<iostream>
using namespace std;
struct ArrayQ
{
    int rear,front;
    int capacity;
    int *array;
};
struct ArrayQ* createQueue(int capacity)
{
    struct ArrayQ* Q = new ArrayQ;
    if(!Q)
    {
        return NULL;
    }
    
    Q->capacity = capacity;
    Q->rear = Q->front = -1;
    Q->array = (int*)malloc(Q->capacity*sizeof(int));
    if(!Q->array)
    {
        return NULL;
    }
    return(Q);
}
int isEmpty(struct ArrayQ *Q)
{
    return(Q->front==-1);
}
int isFull(struct ArrayQ *Q)
{
    return((Q->rear+1)%Q->capacity==Q->front);
}
int sizeofQueue(struct ArrayQ *Q)
{
    if(isEmpty(Q))
    {
        return(0);
    }
    if(isFull(Q))
    {
        return(4);
    }
    return(((Q->capacity-Q->front+Q->rear+1))%Q->capacity);
}
void enQueue(struct ArrayQ *Q,int data)
{
    if(isFull(Q))7
    {
        cout<<"Queue Overflow!!.\n";
        return;
    }
    else
    {
        Q->rear = (Q->rear+1)%Q->capacity;
        Q->array[Q->rear] = data;
        if(Q->front == -1)
        {
            Q->front = Q->rear;
        }
    }
}
int deQueue(struct ArrayQ *Q)
{   
    int t = -1;
    if(isEmpty(Q))
    {
        cout<<"Queue is Empty\n";
        return -1;
    }
    else
    {
        t = Q->array[Q->front];
        Q->array[Q->front] = 0;
        if(Q->front == Q->rear)
        {
            Q->front=Q->rear=-1;
        }
        else
        {
            Q->front = (Q->front+1)%Q->capacity;
            
        }
    }
    return t;
}
void deleteQueue(struct ArrayQ *Q)
{
    if(Q)
    {
        if(Q->array)
        {
            free(Q->array);
        }
        free(Q);
    }
}
void display(struct ArrayQ *Q,int capacity)
{
    if(isEmpty(Q))
    {
        cout<<"Queue is empty\n";
        return;
    }
    else
    {
        int i = 0;
        cout<<"|||||||||------>>> Queue is ------->>>:";
        while(i < capacity)
        {
            cout<<Q->array[i]<<" --> ";
            i++;
        }
        cout<<endl;
    }
    return;
}
int main()
{
    int ch,data;
    int capacity = 4;
    struct ArrayQ *Q = NULL;
    Q = createQueue(capacity);
    cout<<"|--------------------->>> Queue Program <<<-------------------|\n\n\n";
    cout<<"|-------->>> 1) Check is the Queue empty \n";
    cout<<"|-------->>> 2) Check is the Queue Full \n";
    cout<<"|-------->>> 3) Check the Size of Queue \n";
    cout<<"|-------->>> 4) Insertion (EnQueue) \n";
    cout<<"|-------->>> 5) Deletion (DeQueue) \n";
    cout<<"|-------->>> 6) Display Queue \n";
    cout<<"|-------->>> 7) Delete the Queue \n";
    cout<<"|-------->>> 8) Exit \n";
    while(1)
    {
        cout<<"Enter your choice"<<" ----->>> ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1:
            {
                int n = isEmpty(Q);
                if(n == 0)
                {
                    cout<<"Queue is not Empty\n";
                    break;
                }
                cout<<"Queue is empty\n";
                break;
            }
            case 2:
            {
                int n = isFull(Q);
                if(n == 0)
                {
                    cout<<"Queue is not Full\n";
                    break;
                }
                cout<<"Queue is Full\n";
                break;
            }
            case 3:
            {
                int n = sizeofQueue(Q);
                cout<<"Queue size is"<<" -------->> "<<n<<endl;
                break;
            }
            case 4:
            {
                int data;
                cout<<"Enter the data for Queue:"<<" ----->> ";
                cin>>data;
                cout<<endl;
                enQueue(Q,data);
                break;
            }
            case 5:
            {
                int n = deQueue(Q);
                cout<<"Deleted element is"<<" -->> "<<n<<endl;
                break;
            }
            case 6:
            {
                display(Q,capacity);
                break;
            }
            case 7:
            {
                deleteQueue(Q);
                cout<<"|----------------->>> Queue is Deleted <<<----------------|\n";
                break;
            }
            case 8:
            {
                exit(0);
            }
            default:
            {
                cout<<"Invalid Choice"<<endl;
                break;
            }
        }
    }
    return 0;
}


/*
OUTPUT:
|---------------------> Queue Program <<<-------------------|


|--------> 1) Check is the Queue empty 
|--------> 2) Check is the Queue Full 
|--------> 3) Check the Size of Queue 
|--------> 4) Insertion (EnQueue) 
|--------> 5) Deletion (DeQueue) 
|--------> 6) Display Queue 
|--------> 7) Delete the Queue 
|--------> 8) Exit 
Enter your choice -----> 1
Queue is empty
Enter your choice -----> 3
Queue size is -------->> 0
Enter your choice -----> 4
Enter the data for Queue: ----->> 1
Enter your choice -----> 4
Enter the data for Queue: ----->> 2
Enter your choice -----> 4
Enter the data for Queue: ----->> 3
Enter your choice -----> 4
Enter the data for Queue: ----->> 4
Enter your choice -----> 2
Queue is Full
Enter your choice -----> 5
Deleted element is -->> 1
Enter your choice -----> 6
|||||||||------> Queue is ------->:0 --> 2 --> 3 --> 4 --> 
Enter your choice -----> 3
Queue size is -------->> 3
Enter your choice -----> 4
Enter the data for Queue: ----->> 1
Enter your choice -----> 3
Queue size is -------->> 0
Enter your choice -----> 6
|||||||||------> Queue is ------->:1 --> 2 --> 3 --> 4 --> 
Enter your choice -----> 7
|-----------------> Queue is Deleted <<<----------------|
Enter your choice -----> 
*/
