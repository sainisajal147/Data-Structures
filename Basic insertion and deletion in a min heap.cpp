//did not consider the heapify function
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int > h;
void Swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int left(int i)
{
    return 2*(i+1)-1;
}
int right(int i)
{
    return 2*(i+1);
}
int parent(int i)
{
    return floor((i+1)/2)-1;
}
void Insert(int b )
{
    if(h.empty())
    {
        h.push_back(b);
    }
    else
    {
        h.push_back(b);
        int n=h.size()-1;
        while(h[parent(n)]>h[n])
        {
            Swap(h[parent(n)],h[n]);
            n=parent(n);
        }
    }
}
void Delete(int n)
{
    h[0]=h[n];
    n=n-1;
    int i=0;
    while((h[i]>h[left(i)] || h[i]>h[right(i)])&& i<n)
    {
        if(h[i]>h[left(i)])
        {
        swap(h[i],h[left(i)]);
        i=left(i);
        }
        else if(h[i]>h[right(i)])
        {
            swap(h[i],h[right(i)]);
        i=right(i);
        }
    }
}
int show()
{
    return h[0];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
   //  Insert(2);
   // Insert(1);  
   // Insert(5);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int b;
            cin>>b;
            Insert(b);
        }
        else if(a==2)
        {
            int c;
            cin>>c;
            int n=h.size()-1;
            Delete(n);
            n=n-1;
        }
        else if(a==3)
        {
            /*for(int k=0;k<h.size();k++)
            {
                cout<<h[k]<<" ";
            }*/
            cout<<show()<<"\n";
        }
        //cout<<"\n";
    }
    return 0;
}
