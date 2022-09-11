#include<bits/stdc++.h>
using namespace std;
class Hash
{
    int BUCKET;
    list<int> *table;
    public:
        Hash(int b);
        int mapping(int key)
        {
            return key % BUCKET;
        }
        void insert(int key);
        void deleteNode(int key);
        void display();
        
};
Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}
 void Hash::insert(int key)
{
    int index = mapping(key);
    table[index].push_back(key);
}
void Hash::deleteNode(int key)
{
    int index = mapping(key);
    list<int>::iterator i;
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
    int a[] = {12,43,32,56,12,21,54,45};
    int n = sizeof(a)/sizeof(a[0]);
    Hash h(7);
    for(int i = 0;i<n;i++)
    {
        h.insert(a[i]);
    }
    h.display();
    cout<<endl;
    cout<<endl;
    h.deleteNode(43);
    h.display();
    return 0;
}
