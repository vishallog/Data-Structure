#include<iostream>
using namespace std;
void quick(int a[],int n, int beg,int end,int *loc);
void quick_sort(int a[],int n);
int main()
{
    int a[] = {12,5,22,4,33,23,32,76};
    int n = sizeof(a)/sizeof(a[0]);
    quick_sort(a,n);
  
    for(int i = 0;i<n;i++)
        cout<<a[i]<<"   ";
    return 0;
    
}
void quick(int a[],int n, int beg,int end,int *loc)
{
    int left,right;        
    *loc = beg;
    left = beg;
    right = end;
step2:
    while(a[*loc] <= a[right] && *loc!=right)
    {
        right--;
    }
    if(*loc == right)
        return;
    if(a[*loc]>a[right])
    {
        int temp = a[*loc];
        a[*loc] = a[right];
        a[right] = temp;
        *loc = right;
    }
    goto step3;
step3:
    while(a[left]<=a[*loc] && left!=*loc)
    {
        left++;
    }
    if(left == *loc)
        return;
    if(a[left]>a[*loc])
    {
        int temp = a[left];
        a[left] = a[*loc];
        a[*loc] = temp;
    }
    goto step2;
}








void quick_sort(int a[],int n)
{
    
    int beg,end;
    int top = -1,loc = 0;
    int lower[10],upper[10];
    if(n>1)
    {
       
        top++;
        lower[top] = 0;
        upper[top] = n-1;
        
    }
    while(top!=-1)
    {
        
        beg = lower[top];
        end = upper[top];
        top--;
        for(int i = 0;i<n;i++)
            cout<<a[i]<<"   ";
        cout<<endl;
        quick(a,n,beg,end,&loc);
        if(beg<loc-1)
        {
            top++;
            lower[top] = beg;
            upper[top] = loc-1;
        }
        if(loc+1 < end)
        {
            top++;
            lower[top] = loc+1;
            upper[top] = end;
        }
    }
}
