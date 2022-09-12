#include<bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
class Hash
{
    int BUCKET;
    list<string> *table;
    public:
        Hash(int b);
        int mapping(string key)
        {
            int c = key.size();
            return c % BUCKET;
        }
        void insert(string key);
        void deleteNode(string key);
        void display();
        
};
Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<string>[BUCKET];
}
 void Hash::insert(string key)
{
    int index  = mapping(key);
    table[index].push_back(key);
}
void Hash::deleteNode(string key)
{
    int index = mapping(key);
    list<string>::iterator i;
    for(i = table[index].begin();i != table[index].end();i++)
    {
        if(*i == key)
        {
            break;
        }
    }
    if(i != table[index].end())
    {
        table[index].erase(i);
    }
}
void Hash::display()
{
    for(int i = 0;i<BUCKET;i++)
    {
        cout<<i;
        for(auto x:table[i])
        {
            cout<<" --> "<<x;
        }
        cout<<endl;
    }
}
int main()
{
    string a[] = {"vishal","Mahesh","sarthak","anish","manisha","sanchit"};
    int n = sizeof(a)/sizeof(a[0]);
    Hash h(7);
    for(int i = 0;i<n;i++)
    {
        h.insert(a[i]);
    }
    h.display();
    cout<<endl;
    cout<<endl;
    h.deleteNode(a[2]);
    h.display();
    return 0;
}
