#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int parent = (i - 1)/2;
    if(arr[parent]>0)
    {
        if(arr[i] > arr[parent])
        {
            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;
            heapify(arr,n,parent);
        }
    }
    
}
void insertHeap(int arr[],int n,int data)
{
    n = n + 1;
    arr[n-1] = data;
    heapify(arr,n,n-1);
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
    insertHeap(arr,n,4);
    printHeap(arr,n,-1);
    return 0;
}
