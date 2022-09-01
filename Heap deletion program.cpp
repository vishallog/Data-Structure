#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int large = i;
    int l = 2 * i + 1;
    int r = 2 + i + 2;
    if(l<n && arr[l]>arr[large])
    {
        large = l;
    }
    if(r<n&&arr[r]>arr[large])
    {
        large = r;
    }
    
    
    if(large != i)
    {
        int temp = arr[i];
        arr[i] = arr[large];
        arr[large] = temp;
        heapify(arr,n,large);
    }
}
void deleteHeap(int arr[],int n)
{
    int temp = arr[n-1];
    arr[0] = temp;
    n = n-1;
    heapify(arr,n,0);
}
void printHeap(int arr[],int n,int i)
{
    if(i == n - 1)
    {
        return;
    }
    i++;
    cout<<arr[i]<<" -->> ";
    printHeap(arr,n,i);
    return;
}
int main()
{
    int arr[] = {10,5,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    deleteHeap(arr,n);
    printHeap(arr,n-1,-1);
    return 0;
}
