#include<iostream>
using namespace std;
struct mway
{
    int index = -1;
    static const int m = 3;
    int k[m-1];
    mway *child[m] = {NULL};
};
mway* createNode(int data)
{
    mway *node = new mway;
    (node->index)++;
    node->k[node->index] = data;
    return node;
}
void sort(mway *s)
{
    //cout<<s->index<<endl;
    int temp;
    for(int i = 0; i <(s->index);i++)
    {
        for(int j = 0; j<(s->index);j++)
        {
            if((s->k[j])>(s->k[j+1]))
            {
                temp = s->k[j];
                s->k[j] = s->k[j+1];
                s->k[j+1] = temp;
            }
        }
    }
}
mway* insert(int data,mway *root)
{
    if(root == NULL)
    {
        root = createNode(data);
        return root;
    }
    else
    {
        mway *ptr = root;
        mway *par = NULL;
        int store;
        while(ptr != NULL)
        {
            par = ptr;
            if((ptr->index)<(ptr->m)-2)
            {
                //cout<<"Data is available"<<endl;
                //cout<<ptr->k[0]<<"   "<<ptr->index<<"  "<<ptr->k[1]<<"   "<<(ptr->index)<<endl;
                (ptr->index)++;
                ptr->k[ptr->index] = data;
                sort(ptr);
                //cout<<ptr->k[0]<<"   "<<ptr->index<<"  "<<ptr->k[1]<<"   "<<(ptr->index)<<endl;
                return root;
            }
            else 
            {
                if(data<(ptr->k[0]))
                {
                    ptr = ptr->child[0];
                }
                else if(data>(ptr->k[1]))
                {
                    //cout<<ptr->k[1]<<"-->>";
                    //cout<<data<<"===>>>>";
                    //cout<<ptr<<"==>>";
                    ptr = ptr->child[2];
                    //cout<<ptr<<endl;
                }
                else
                {
                    //cout<<ptr->k[1]<<endl;

                    for(int i=1;i<=(ptr->m)-2;i++)
                    {
                        if(data>ptr->k[i-1] && data<ptr->k[i])
                        {
                            //cout<<data<<endl;
                            store = i;
                            ptr = ptr->child[1];
                            //cout<<ptr<<endl;
                            break;
                        }
                    }
                }
            }
        }
        if(data<par->k[0])
        {
            
            par->child[0] = createNode(data);
        }
        else if(data>(par->k[1]))
        {
            //cout<<data<<endl;
            par->child[2] = createNode(data);
        }
        else if(data>par->k[0] && data<par->k[1])
        {
            //cout<<par->k[0]<<"  "<<par->k[1]<<endl;
            //cout<<par->k[1]<<endl;
            par->child[1] = createNode(data);
            //cout<<par->child[1]->k[0]<<"   "<<par->child[1]->index<<"  "<<par->child[1]->k[1]<<"   "<<par->child[1]->index<<endl;
        }
    }
    //cout<<"node is inserted"<<endl;
    return root;
}
void display(mway *root)
{
    mway *ptr = root;
    if(ptr)
    {    
        for(int i = 0;i<=ptr->index;i++)
        {
            cout<<ptr->k[i]<<" -->> ";
        }
        cout<<endl;
        display(ptr->child[0]);
        display(ptr->child[1]);
        display(ptr->child[2]);
    }
}
int main()
{
    mway *root = NULL;
    root = insert(10,root);
    root = insert(15,root);
    root = insert(12,root);
    root = insert(2,root);
    root = insert(13,root);
    root = insert(22,root);
    root = insert(25,root);
    root = insert(30,root);
    root = insert(40,root);
    root = insert(5,root);
    display(root);
    return 0;
}
