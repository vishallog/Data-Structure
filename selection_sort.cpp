#include <iostream>
using namespace std;
void selection_sort(int a[],int n);
int main() {
 int a[] = {20,10,30,40,50,60,70};
 int n = sizeof(a)/sizeof(a[0]);
 selection_sort(a,n);

 for(int i=0;i<n;i++)
 {
     cout<<a[i]<<"   ";
 }
 cout<<endl;
    return 0;
}

void selection_sort(int a[],int n)
{
    int temp = 0;
    for(int i=0;i<n;i++)
    {
        int flag = 0;
        temp = i;
        for(int j = i; j<n-1;j++)
        {
            if(a[temp] > a[j+1])
            {
                flag = 1;
                temp = j+1;
            }
        }
        if(flag == 0)
        {
            cout<<i<<endl;
            break;
        }
        int c = a[i];
        a[i] = a[temp];
        a[temp] = c;
    }
    return;
}
