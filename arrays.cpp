#include <iostream>
#include<vector>
using namespace std;
int * merg(int a[], int b[], int m,int n)
{
    int *c=NULL;
    c= new int[m+n];
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
        if(a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    for(;i<m;i++)
        c[k++]=a[i++];
    for(;j<n;j++)
        c[k++]=b[j++];
    return c;
}
void single_miss(int a[], int n)
{
    int dif=a[0],l=a[0],h=a[n-1];
    //int *b= new int[5];
    for(int i=0;i<n;i++)
    {
        if(a[i]-i!=dif)
          {
              int k=a[i]-i;
              while(k>dif )
               {
                   cout<<i+dif<<" ";
                    dif++;
               }
          }
    }
}
void hash_t(int *a, int n,int l, int h)
{
    int *H=new int[h];
    H[h]={0};
    for(int i=0;i<n;i++)
    {
        H[a[i]]++;
    }
    for(int i=l;i<h;i++)
    {
        if(H[i]==0)
            cout<<i<<" ";
    }
}
void dup_sor(int *a,int n)
{
    int j=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            j=i+1;
            while(a[j]==a[i]) j++;
            cout<<a[i]<<"times"<<j-i<<" ";
            i=j-1;
        }
    }
}
void dup_has(int *a, int n,int h)
{
    int * H=new int[h];
   // H[h]={0};
   for(int i=0;i<h;i++) H[i]=0;
    for(int i=0;i<n;i++)
    {
        H[a[i]]++;
    }
    for(int i=0;i<h;i++)
    {
        if(H[i]>1)
        {
            cout<<i<<"times"<<H[i]<<" ";
        }
    }
}
int main()
{
    int a[]={3,6,8,8,10,12,15,15,15,20};//,b[6]={2,4,6,7,12,16};
   // cout<<
 //  single_miss(a,8);
 //  hash_t(a,8,1,11);
 dup_has(a,10,20);
   /* for(int i=0;i<5;i++)
    {
        cout<<c[i]<<" ";
        if(c[i]==0)
        break;
    }*/

    return 0;
}
