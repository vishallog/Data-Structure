#include <iostream>
using namespace std;
void bubble_sort(int a[],int n);
int main() {
 int a[] = {10,43,6,76,23,65,12};
 int n = sizeof(a)/sizeof(a[0]);
 bubble_sort(a,n);

 for(int i=0;i<n;i++)
 {
     cout<<a[i]<<"   ";
 }
 cout<<endl;
    return 0;
}

void bubble_sort(int a[],int n)
{
    int temp = 0;
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return;
}
