#include<iostream>
using namespace std;
void print(int str[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<str[i]<<" ";
    }
    cout<<endl;
}
void bin(int n,int str[],int i)
{
    if(i==n)
    {
        print(str,n);
        return;
    }
    else
    {
        str[i] = 0;
        bin(n,str,i+1);
        str[i] = 1;
        bin(n,str,i+1);
        
    }
}
int main()
{
    int n = 4;
    int str[n];
    bin(n,str,0);
    return 0;
}


/*
OUTPUT:

0 0 0 0 
0 0 0 1 
0 0 1 0 
0 0 1 1 
0 1 0 0 
0 1 0 1 
0 1 1 0 
0 1 1 1 
1 0 0 0 
1 0 0 1 
1 0 1 0 
1 0 1 1 
1 1 0 0 
1 1 0 1 
1 1 1 0 
1 1 1 1 
*/
