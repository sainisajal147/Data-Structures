#include <iostream>

using namespace std;

void Insert(int h[10],int data)
{
    int index=data%10,i=1;
    while(h[index])
    {
        index=(data+i*i)%10;
        i++;
    }
    h[index]=data;
}
void Search(int h[10],int data)
{
    int index=data%10,i=1;
    while(h[index])
    {
        if(h[index]==data)
        {
            cout<<"element found\n";
            return;
        }
        index=(data+i*i)%10;
        i++;
    }
    cout<<"element not found\n";
}
void Delete(int h[10],int data)
{
    int index=data%10,i=1;
    while(h[index])
    {
        if(h[index]==data)
        {
            h[index]=-1;
            return;
        }
        index=(data+i*i)%10;
        i++;
    }
}
int main()
{
    int h[10]={0};
    int a[]={23,43,13,7};
    for(int i=0;i<4;i++)
    {
        Insert(h,a[i]);
    }
    for(int i=0;i<10;i++)
    {
        cout<<h[i]<<" ";
    }
    cout<<endl;
    Search(h,13);
    Delete(h,13);
    Search(h,13);
    for(int i=0;i<10;i++)
    {
        cout<<h[i]<<" ";
    }
    Search(h,7);
    return 0;
}

