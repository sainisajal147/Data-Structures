#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
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
void heapify( vector<int> &a,int i)
{
    static int n=a.size();
    int l=left(i);
    int r=right(i);
    int larg=i;
    if(l<n && a[larg]<a[l])
        larg=l;
    if(r<n && a[larg]<a[r])
        larg=r;
    if(larg!=i)
    {
        swap(a[larg],a[i]);
        heapify(a,larg);
    }
}
int main()
{
    vector<int > a={50,30,16,59,60,20,10,8};
   // for(int i=0;i<9;i++)
     //   {heapify(a,i);}
    for(int i=a.size()-1;i>=0;i--)
    {
        heapify(a,i);
    }
    //cout<<endl;
    //make_heap(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
