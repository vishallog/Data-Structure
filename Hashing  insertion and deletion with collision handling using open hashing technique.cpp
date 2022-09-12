// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
#include <cstring>
using namespace std;
string arr[7] = {"NULL","NULL","NULL","NULL","NULL","NULL","NULL"};
int n = 7;
int mapping(string value)
 { 
    int c = value.size();
    //cout<<"\n"<<c<<endl;
    return c%7;
}
void insert(string value)
{
    int index = mapping(value);
    if(arr[index] == "NULL")
    {
        arr[index] = value;
    }
    else
    {
        while(arr[index]!="NULL")
       {
           if(index<n)
                index = index + 1;
            else
                break;
       }
       while(arr[index]!="NULL")
       {
           if(index > 0)
                index = index - 1;
            else
                break;
       }
        if(arr[index]!="NULL")
            cout<<"\n\nHash table is FULL"<<endl;
        else
            arr[index] = value;
    }
}
void deleteKey(string value)
{
    int index = mapping(value);
    if(arr[index] == value)
    {
        arr[index] = "NULL";
    }
    else
    {
        while(arr[index]!= value)
       {
           if(index<n)
                index = index + 1;
            else
                break;
       }
       while(arr[index]!= value)
       {
           if(index > 0)
                index = index - 1;
            else
                break;
       }
        if(arr[index]!= value)
            cout<<"\n\n Key not found in Hash table"<<endl;
        else
            arr[index] = "NULL";
    }
}
void display()
   {    
        for(int i = 0;i<n;i++)
        {
            cout<<i<<"-->"<<arr[i]<<endl;
        }
        cout<<endl;
   }
int main() {
 
   
  string a[] = {"Asds","Bsdsd","Cdsd","Ddadad","dsa","sdsdadaada","dadasada","dd"};
    int n = 8;
    cout<<"Hash Table"<<endl;
    display();
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        insert(a[i]);
    }
    cout<<"Hash Table After Insertion"<<endl;
    display();
    cout<<endl;
    deleteKey(a[1]);
    
    cout<<"Hash Table After Deletion"<<endl;
    display();
    cout<<endl;
return 0;
   
}
