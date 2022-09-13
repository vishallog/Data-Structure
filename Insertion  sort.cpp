#include<iostream>
using namespace std;
void print(int a[],int n);
void insertion_sort(int a[],int n);
int main()
{
    int a[] = {32,5,3,2,6,7,23};
    int n = sizeof(a)/sizeof(a[0]);
    insertion_sort(a,n);
    cout<<"Last wala:"<<endl;
    print(a,n);
    return 0;
}
void insertion_sort(int a[],int n)
{
    int temp,j;
    for(int i = 1;i<n;i++)
    {
        temp = a[i];
        for(j = i-1;j>=0 && a[j]>temp;j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
        print(a,n);
    }
    return;
}
void print(int a[],int n)
{
    for(int i = 0;i<n;i++)
    {
         cout<<a[i]<<"  ";
    }
    cout<<endl;
    return;
}

