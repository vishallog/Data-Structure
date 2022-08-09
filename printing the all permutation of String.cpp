#include<iostream>
using namespace std;
void permute(string str,int i,int n)
{
    if(i == n)
        cout<<str<<endl;
    else
    {
        for(int j=i;j<=n;j++)
        {
            swap(str[i],str[j]);
            //Recursion called..
            permute(str,i+1,n);
            //backtracking..
            swap(str[i],str[j]);
            
        }
    }
    
}
//driver code..
int main()
{
    string str = "ABC";
    int n = str.size();
    permute(str,0,n-1);
    return 0;
}

/*
ABC
ACB
BAC
BCA
CBA
CAB
*/
