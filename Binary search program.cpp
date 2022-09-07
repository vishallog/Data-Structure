#include<iostream>
using namespace std;
void sort(int arr[],int n)
{
    // bubble sort;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void seq_search(int l[],int n,int ITEM)
{
    int count = 0;
    sort(l,n);//bubble sort
    int L = 0,U = n-1,M,flag = 0;
    while(L<=U)
    {
        count++;
        M = (L+U)/2;
        if(ITEM == l[M])
        {
            flag = 1;
            cout<<"Search succesfull at -->>"<<M;
            cout<<"\n Number of searches required -->> "<<count;            
            break;
        }
        else if(ITEM<l[M])
        {
            U = M-1;
        }
        else
        {
            L = M +1;
        }
    }
    if(flag == 0)
        cout<<"data not found";
        cout<<"\n Number of searches required -->> "<<count;  
    
    return;
}
int main()
{
    int arr[] = {12,3,4,76,8,5,9,23,53,23,65};
    int n = sizeof(arr)/sizeof(arr[0]);
    seq_search(arr,n,6);
}
