// Infix to Postfix converter program..
#include<iostream>
using namespace std;
struct stack
{
    int top;
    int capacity;
    char *array;
};
struct stack* createStack(int capacity)
{
    struct stack* s = new stack;
    s->top = -1;
    s->capacity = capacity;
    s->array = (char*)malloc(s->capacity*sizeof(char));
    return(s);
}
void push(struct stack *s,char c)
{
    if(s->top>=s->capacity-1)
    {
        cout<<"Stack is Overflowing\n";
        return;
    }
    else
    {
        s->top++;
        s->array[s->top] = c ;
    }
    return;
}
char pop(struct stack *s)
{
    char d;
    if(s->top == -1)
    {
        return 0;
    }
    else
    {
        d = s->array[s->top];
        s->top--;
    }
    return d;
}

void display(struct stack *s)
{
    struct stack *v = s;
    if(s->top == -1)
    {
        cout<<"Stack is empty,\n";
        return ;
    }
    else
    {
        for(int i=s->top;i>=0;i--)
        {
            cout<<s->array[i]<<" -->> "; 
        }
        cout<<endl;
    }
    return;
}
int isEmpty(struct stack *s)
{
    if(s->top == -1)
    {
        return 0;
    }
    return 1;
}
int priority (char alpha){
    if(alpha == '+' || alpha =='-')
        return 1;
 
    if(alpha == '*' || alpha =='/')
        return 2;
 
    if(alpha == '^')
        return 3;

 
    return 0;
}
int main()
{
    int ch;
    int i=0;
    char data;
    int capacity = 15;
    struct stack *s = NULL;
    s = createStack(capacity);
    char b[21] = {'A','+','(','(','B','+','C',')','+','(','D','+','E',')','*','F',')','/','G',')','\0'};
    cout<<"Infix is -->>";
    for(int i = 0;b[i]!='\0';i++)
    {
        cout<<b[i];
    }
    cout<<endl;
    cout<<endl;
    string p;
    push(s,'(');
    while(b[i]!='\0')
    {
        if(b[i]=='A' || b[i]=='B' || b[i]=='C' || b[i]=='D' || b[i]=='E' || b[i]=='F' || b[i]=='G')
        {
            p += b[i];
            i++;
        }
        else if(b[i]=='(')
        {
            push(s,'(');
            i++;
        }
        
        else if(b[i] == ')')
        {
            while(s->array[s->top] != '(')
            {
                p += pop(s);
            }
            pop(s);
            i++;
        }
        else 
        {
            while (!isEmpty(s) && priority(b[i]) <= priority(s->array[s->top]))
            {
                p += pop(s);
            }
            push(s,b[i]);
            i++;
            
        }
        
    }
    cout<<"\n Postfix is -->>"<<p;
        
    return 0;
}

/*
OUTPUT:
Infix is -->>A+((B+C)+(D+E)*F)/G)
Postfix is -->>ABC+DE+F*+G/+
*/
