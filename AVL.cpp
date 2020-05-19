#include <iostream>
#include<stack>
#include<queue>
using namespace std;

struct node
{
    int val;
    node * left;
    node * right;
    int ht;
};
int height(node * root)
{
    if(root==NULL) return -1;
    else
    {
        int hl=height(root->left);
        int hr=height(root->right);
        return max(hl,hr)+1;
    }
}
node * newnode(int data)
{
    node * newn = new node();
    newn->val=data;
    newn->left=NULL;
    newn->right=NULL;
    newn->ht=0;
    return newn;
}
int bf(node * root)
{
    return height(root->left)-height(root->right);
}
node * rr(node * root)
{
    node * temp=root->right;
    node * temp1=temp->left;

    temp->left=root;
    root->right=temp1;
    root->ht=max(height(root->left),height(root->right))+1;
    temp->ht=max(height(temp->left),height(temp->right))+1;
    return temp;
}
node * ll(node * root)
{
    node * temp=root->left;
    node * temp1=temp->right;

    temp->right=root;
    root->left=temp1;
    root->ht=max(height(root->left),height(root->right))+1;
    temp->ht=max(height(temp->left),height(temp->right))+1;
    return temp;
}

node * insert(node * root,int val)
{
    if(root==NULL)
        root=newnode(val);
    else
    {
        if(root->val>val)
            root->left=insert(root->left,val);
        else
            root->right=insert(root->right,val);
    }
    node * temp=root;
    queue<node *> q;
    q.push(temp);
    while(!q.empty())
    {
        node * curr=q.front();
        curr->ht=height(curr);
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
        q.pop();
    }

    root->ht = 1 + max(height(root->left), height(root->right));

    //Get the balance factor of parent node
    int balance = bf(root);
    //left left case
    if (balance > 1 && val < root->left->val)
        return ll(root);

    // Right Right Case
    if (balance < -1 && val > root->right->val)
        return rr(root);

    // Left Right Case
    if (balance > 1 && val > root->left->val)
    {
        root->left = rr(root->left);
        return ll(root);
    }

    // Right Left Case
    if (balance < -1 && val < root->right->val)
    {
        root->right = ll(root->right);
        return rr(root);
    }

  return root;
}
void ino(node * root)
{
    if(root)
    {
        ino(root->left);

        cout<<root->val<<" with height of "<<root->ht<<"   ";
        ino(root->right);
    }
}
node * Insert(int a[], int n)
{
    node * root=newnode(a[0]);
    stack<node* > s;
    node * p=root;
    s.push(p);
    int i=1;
    while(i<5)
    {
        if(a[i]<p->val)
        {
            p->left=newnode(a[i]);
            s.push(p);
            p=p->left;
            i++;
        }
        else
        {
            if(a[i]>p->val && a[i]<s.top()->val)
            {
                p->right=newnode(a[i]);
                p=p->right;
                i++;
            }
            else
            {
                p=s.top();
                s.pop();
            }
        }
    }
    return root;
}
int main()
{
    int a[5]={30,20,10,15,25};
    node * t=Insert(a,5);
    ino(t);
    cout<<endl;
    t=insert(t,7);
    ino(t);
    return 0;
}
