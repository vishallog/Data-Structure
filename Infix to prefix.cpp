// Infix to Prefix converter program..
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
        return 1;
    }
    return 0;
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
string postfix(struct stack *s,char b[21],string p)
{
    int i = 0;
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
                //cout<<p;
            }
            pop(s);
            i++;
        }
        else 
        {
            //cout<<"dsds\n";
            while (!isEmpty(s) && priority(b[i]) <= priority(s->array[s->top]))
            {
                //cout<<b[i]<<"-->>"<<s->array[s->top]<<endl;
                p += pop(s);
            }
            //cout<<b[i]<<"-->>"<<s->array[s->top]<<endl;
            push(s,b[i]);
            i++;
            
        }
        
    }
   
    return p;
    
}
void brackets(char b[21])
{
    int i = 0;
    while(b[i]!='\0')
    {
        if(b[i] == '(')
        {
            b[i] = ')';
        }
        else if(b[i] == ')')
        {
            b[i] = '(';
        }
        i++;
    }
    
}
void reverse1(char b[21])
{
    char temp[21];
    temp[20] = '\0';
    int j = 19;
    for(int i = 0;b[i]!='\0';i++)
    {
        //cout<<j<<"-->>"<<b[i]<<endl;
        temp[j] = b[i];
        j--;
    }
    int i=0;
    while(i<=20)
    {
        b[i] = temp[i];
        //cout<<i<<"-->>"<<temp[i]<<endl;
        i++;
    }
    cout<<endl;
}
string reverse2(string p)
{
    int j = 13, i = 0;
    char temp[j];

    temp[j--] = '\0';
    cout<<endl;
    while (j>=0)
    {
        //cout<<j<<"-->>"<<p[i]<<endl;
        temp[j] = p[i];
        j--;
        i++;
    }
    string c;
    for(int i = 0;temp[i]!='\0';i++)
    {
        c += temp[i];
    }
    return c;
}
int main()
{
    int ch;
    int i=0;
    char data;
    int capacity = 15;
    struct stack *s = NULL;
    s = createStack(capacity);
     char b[21] = {'(','A','+','(','(','B','+','C',')','+','(','D','+','E',')','*','F',')','/','G','\0'};
    reverse1(b);
    brackets(b);
    //brackets(b);
    cout<<"Infix is -->>";
    for(i=0;b[i]!='\0';i++)
    {
        cout<<b[i];
    }
    string p;
    p = postfix(s,b,p);
    //cout<<"\n Postfix is -->>"<<p;
    p = reverse2(p);
    cout<<endl;
    cout<<"\n Prefix is -->>"<<p;
        
    return 0;
}

/*
OUTPUT:
Infix is -->>G/(F*(E+D)+(C+B))+A)
             --------------------  

 Prefix is -->>+A/++BC*+DEFG
               -------------
 */
