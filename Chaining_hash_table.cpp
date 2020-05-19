#include <iostream>
#include<vector>
using namespace std;
struct node
{
    int data;
    node* next;
};
void Insert(node * &head,int data)
{
    node * newn=new node();
    newn->data=data;
    newn->next=NULL;
    if(head==NULL)
        {
            head=newn;
            return ;
        }
    else if(head->data>data)
    {
        newn->next=head;
        head=newn;
        return ;
    }
    node * temp=head;
    node * temp1=NULL;
    while(temp->data<data && temp->next)
        {
            temp1=temp;
            temp=temp->next;
        }
        if(temp->data<data)
            temp->next=newn;
            else
        {
             temp1->next=newn;
            newn->next=temp;
        }
}
void Delete(node * &head, int data)
{
    if(head->data==data)
    {
        node * temp=head;
        head=head->next;
        delete temp;
        return;
    }
    node * temp=head;
    node * temp1=NULL;
    while(temp->data!=data && temp->next)
        {
            temp1=temp;
            temp=temp->next;
        }
    if(temp->data==data)
    {
    temp1->next=temp->next;
    delete temp;
    }
}
void Search(node **h,int data)
{
    int index=data%10;
    node * temp=h[index];
    if(temp==NULL)
    {
        cout<<"element does'nt exist\n";
            return;
    }
    while(temp->data<data && temp->next)
    {
        temp=temp->next;
    }
    if(temp->data==data)
    {
        cout<<"element found :\n";
        return;
    }
    if(temp->next==NULL)
    {
        cout<<"element does'nt exist\n";
            return;
    }
}
void disp(node *h)
{
    if(h)
    {
        cout<<h->data<<" ";
        disp(h->next);
    }
}
int main()
{
    node **h=NULL;
    h=new node*[10];
    for(int i=0;i<10;i++)
    {
        h[i]=NULL;
    }
    vector<int> a={16,12,25,39,6,122,5,68,75};
    for(int i=0;i<a.size();i++)
    {
        int index=a[i]%10;
        Insert(h[index],a[i]);
    }
    //Insert(h[0],2);
    Search(h,5);
    Delete(h[5%10],5);
    Search(h,5);
    return 0;
}
