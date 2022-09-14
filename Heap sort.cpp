#include<iostream>
using namespace std;
void heapify(int h[],int n,int i)
{
    int l = 2*i+1;
    int r = 2 *i+2;
    int largest = i;
    if(l<n && h[l] > h[largest])
    {
        largest = l;
    }
    if(r<n && h[r] > h[largest])
    {
        largest = r;
    }
    if(i!=largest)
    {
        int temp = h[i];
        h[i] = h[largest];
        h[largest] = temp;
        heapify(h,n,largest);
    }
}
void BuildHeap(int h[],int n)
{
    for(int i = (n-1)/2;i>=0;i--)
    {
        heapify(h,n,i);
    }
}
void Heap_sort(int h[],int n)
{
    for(int i = n-1;i>=0;i--)
    {
        int temp = h[0];
        h[0] = h[i];
        h[i]  = temp;
        heapify(h,i-1,0);
        
    }
}
int main()
{
    int h[]= {3,1,6,5,2,7,9,4};
    int n = sizeof(h)/sizeof(h[0]);
    BuildHeap(h,n);
    Heap_sort(h,n);
    for(int i = 0;i<n;i++)
        cout<<h[i]<<"  ";
    return 0;
}
