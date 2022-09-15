#include<iostream>
using namespace std;
void merge_sort(int a[],int l,int r);
void merge(int a[],int l,int m,int r);
void display(int a[],int r);
int main()
{
    int a[] = {10,4,2,6,72,8,3,22};
    int n = sizeof(a)/sizeof(a[0]);
    display(a,n);
    merge_sort(a,0,n-1);
    cout<<endl;
    cout<<endl;
    display(a,n);
    
    return 0;
}
void merge_sort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
void merge(int a[],int l,int mid,int r)
{
    int b[r+1];
    int k = l;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r)
    {
        if(a[i]>a[j])
        {
            b[k] = a[j];
            j++;
        }
        else
        {
            b[k] = a[i];
            i++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=r)
        {
            b[k] = a[j];
            j++;
            k++;
        }
        
    }
    else
    {
        while(i<=mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for(int i = l;i<=r;i++)
    {
        a[i] = b[i];
    }
}
void display(int a[],int r)
{
    for(int i = 0;i<r;i++)
    {
        cout<<a[i]<<"  ";
    }
}
