#include <iostream>
using namespace std;
void modified_bubble_sort(int a[],int n);
int main() {
 int a[] = {20,10,30,40,50,60,70};
 int n = sizeof(a)/sizeof(a[0]);
 modified_bubble_sort(a,n);

 for(int i=0;i<n;i++)
 {
     cout<<a[i]<<"   ";
 }
 cout<<endl;
    return 0;
}

void modified_bubble_sort(int a[],int n)
{
    int flag;
    int temp = 0;
    for(int i=0;i<n;i++)
    {
        flag = 0;
        for(int j = 0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                flag = 1;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag == 0)
        {
            cout<<i<<endl;
            break;
        }
    }
    return;
}
