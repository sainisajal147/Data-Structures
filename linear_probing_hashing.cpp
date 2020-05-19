#include <iostream>

using namespace std;

void Insert(int h[10],int data)
{
    int index=data%10,i=1;
    while(h[index])
    {
        index=(data+i)%10;
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
        index=(data+i)%10;
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
        index=(data+i)%10;
        i++;
    }
}
int main()
{
    int h[10]={0};
    int a[]={26,30,45,23,25,43,74,19,29};
    for(int i=0;i<9;i++)
    {
        Insert(h,a[i]);
    }
    for(int i=0;i<10;i++)
    {
        cout<<h[i]<<" ";
    }
    cout<<endl;
    Search(h,25);
    Delete(h,25);
    Search(h,25);
    for(int i=0;i<10;i++)
    {
        cout<<h[i]<<" ";
    }
    return 0;
}

