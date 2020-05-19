#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

/*void heapify(vector<int> a,int i)
{
    int l=left(i);
    int r=right(i);
}*/
void Swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
class heap
{
private:
    vector<int > v;
public:
    int n=0;
    int left(int i)
    {
        return (i+1)*2-1;
    }
    int right(int i)
    {
        return (i+1)*2;
    }
    int parent(int i)
    {
        return floor((i+1)/2)-1;
    }
    void Insert(int b)
    {
        if(v.empty())
        {
            v.push_back(b);
        }
        else if(v.size()==1)
        {
            v.push_back(b);
                if(v[0]<b)
                swap(v[0],v[1]);
        }
        else
        {
            v.push_back(b);
            int i=v.size()-1;
            while(v[parent(i)]<v[i])
            {
                swap(v[parent(i)],v[i]);
                i=parent(i);
            }
        }
        n++;
    }
    void del()
    {
       swap(v[0],v[n-1]);
       n--;
       int k=0;
       while(left(k)<n-1)
       {
           if(v[left(k)]>v[right(k)])
           {
               if(v[k]<v[left(k)])
               {swap(v[k],v[left(k)]);
               k=left(k);}
               else
                break;
           }
           else
           {
               if(v[k]<v[right(k)])
               {swap(v[k],v[right(k)]);
               k=right(k);}
               else
                break;
           }
       }

       /*int i,j,x,temp,val;
         val=v[1];
         x=v[n];
         v[1]=v[n];
         v[n]=val;
         i=1;j=i*2;
         while(j<=n-1)
         {
                 if(j<n-1 && v[j+1]>v[j])
                 j=j+1;
                 if(v[i]<v[j])
                 {
                 temp=v[i];
                 v[i]=v[j];
                 v[j]=temp;
                 i=j;
                 j=2*j;
                 }
                 else
                 break;
        }
        n--;*/
    }
    int top()
    {
        return v[0];
    }
    void disp()
    {
        for(int q=0;q<n;q++)
        {
            cout<<v[q]<<" ";
        }
    }
    void dsor()
    {
     for(int q=n;q<v.size();q++)
        {
            cout<<v[q]<<" ";
        }
    }
};
int main()
{
    heap h;
   //int n;
   //cout<<"enter the no. of elements:\n";
   //cin>>n;
   //cout<<"enter elements:\n";
   /*for(int i=1;i<n;i++)
   {
       //int a;
       //cin>>a;
       h.Insert(i);
   }*/
   h.Insert(50);
   h.Insert(30);
   h.Insert(20);
   h.Insert(15);
   h.Insert(10);
   h.Insert(8);
   h.Insert(16);
   h.Insert(60);
    h.disp();
    cout<<endl;
    cout<<h.top()<<endl;
    h.del();
    cout<<h.top()<<endl;
    h.del();
    cout<<h.top()<<endl;
    h.del();
    cout<<h.top()<<endl;
    h.del();
    cout<<h.top()<<endl;
    h.del();
    cout<<h.top()<<endl;
    h.del();
    cout<<h.top()<<endl;
    h.del();
    h.del();
    h.dsor();
    cout<<h.n;
    return 0;
}
