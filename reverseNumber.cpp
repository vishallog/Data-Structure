// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int reverse(int n)
{
    int i = 0;
    int r;
    while(n!=0)
    {
        r = n % 10;
        i = i * 10 + r;
        n = n/10;
    }
    return i;
}
int main() {
    int count = 0,count1 = 0;
   for(int i=0;i<10000000;i++)
   {
        int c = reverse(i);
        if(i == c)
        {
            count++;
            //cout<<i<<endl;
        }
        else
        {
            count1++;
        }
   }
    cout<<"total Numbers same even if we reversed it are"<<" -->> "<<count;
    cout<<"\n\ntotal Numbers different even if we reversed it are"<<" -->> "<<count1;
    return 0;
}
