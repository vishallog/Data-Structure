#include<iostream>
using namespace std;
void seq_search(int l[],int n,int ITEM)
{
    int i,falg = 1,j = 0;
    for(i=0;i<=n-1;i++)
    {
        if(l[i] == ITEM)
        {
            j =i;
            falg = 0;
            break;
        }
    }
    
    if(falg == 0)
        cout<<"Item found at -->> "<<j;
    else
        cout<<"Item not found";
    return;    
}
int main()
{
    int arr[] = {12,3,4,76,8,5,9,23,53,23,65};
    int n = sizeof(arr)/sizeof(arr[0]);
    seq_search(arr,n,65);
}
