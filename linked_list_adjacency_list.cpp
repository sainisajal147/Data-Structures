#include <iostream>

using namespace std;
struct node{
int data;
node * next;
};
node * getnode(int data)
{
    node * newn=new node();
    newn->data=data;
    newn->next=NULL;
    return newn;
}
void Insert(node * &head,int data)
{
    if(head==NULL)
        {
            head=getnode(data);
            return ;
        }
    else
        {
            node * temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=getnode(data);
        }
}
void disp(node **G,int n)
{
    for(int i=0;i<n;i++)
    {
        node * temp=G[i];
        cout<<i<<"->";
        while(temp->next)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"\n";
    }
}
void dis( node * head)
{
    if(head)
    {
        cout<<head->data<<"->";
        dis(head->next);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        node **G=NULL;
        G=new node *[v];
        for(int i=0;i<v;i++)
        {
            G[i]=NULL;
        }
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin>>a>>b;
            Insert(G[a],b);
            Insert(G[b],a);
        }
        disp(G,v);

    }
    return 0;
}

