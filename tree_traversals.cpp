#include <iostream>
#include<stack>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};
node * Insert(node * t,int data)
{
    if(t==NULL)
        {
            node * newn=new node();
            newn->data=data;
            newn->left=NULL;
            newn->right=NULL;
            t=newn;
        }
    else if(data<=t->data)
        t->left=Insert(t->left,data);
    else
        t->right=Insert(t->right,data);
    return t;
}
void disp_pre(node *t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        disp_pre(t->left);
        disp_pre(t->right);
    }
}
void itr_pre(node *t)
{
    stack<node *> s;
    s.push(t);
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        t=s.top();
        s.pop();
        if(t->right!=NULL) s.push(t->right);
        if(t->left!=NULL) s.push(t->left);
    }
}
void itr_pre1(node *t)
{
    stack<node *> s;
    while(!s.empty() || t)
    {
        if(t)
        {
            cout<<t->data<<" ";
            s.push(t);
            t=t->left;
        }
        else
        {
            s.pop();
            t=s.top();
            t=t->right;
        }
    }
}
int main()
{
    node * t=NULL;
    t=Insert(t,12);
    t=Insert(t,7);
    t=Insert(t,13);
    t=Insert(t,5);
    t=Insert(t,8);
    t=Insert(t,14);
  // disp_pre(t);
    itr_pre1(t);
    return 0;
}
