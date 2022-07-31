#include<iostream>
using namespace std;

int func(int a);
int main()
{
int n;
n=func(3);
cout<<"factorail is:"<<n;
}
int func(int a)
{
int s;
if(a==1){
return(a);
}
s=a*func(a-1);
return(s);
}
