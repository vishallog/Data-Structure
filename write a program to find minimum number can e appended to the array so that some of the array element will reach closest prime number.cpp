#include <iostream>
#include<vector>
using namespace std;
int closestPrime(int n)
{
    n = n + 1;
    int i = 2;
    while(n!=0)
    {
        if(n % i != 0)
        {
            return n;
            break;
        }
        i++;
        n++;
    }
}
int main() {
    vector< int > arr = {12,28,15,14};
    int count = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<n;i++)
    {
        count = count + arr[i];
    }
    
    
    int r = closestPrime(count);
    int d = r - count;
    arr.push_back(d);
      for(int i = 0;i<n-1;i++)
    {
        cout<<arr[i]<<" -->> ";
    }
    return 0;
}
