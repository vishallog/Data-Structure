// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int NthPentonacci(int i)
{
    if(i==0)
    {
        return(0);
    }
    else if(i==1)
    {
        return(1);
    }
    else if(i==2)
    {
        return(2);
    }
    else if(i==3)
    {
        return(3);
    }
    else if(i==4)
    {
        return(4);
    }
    
    return (NthPentonacci(i-1)+NthPentonacci(i-2)+NthPentonacci(i-3)+NthPentonacci(i-4)+NthPentonacci(i-5));
}

int main() {
    int i;
   cout << "Enter the Nth number of series : ";
   cin >> i;
   
   cout << "\nNth number of Pentonnaci Series : ";
   i = NthPentonacci(i-1);
   cout<<"\n"<<i;
   return 0;
}

