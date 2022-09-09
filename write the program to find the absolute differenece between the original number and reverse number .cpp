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
    int n = 245;
    int r = reverse(245);
    int abs_diff  = r - n;
    cout<<"\n\nThe absolute difference between Original Number and Reverse number is"<<" -->> "<<abs_diff;
    return 0;
}
