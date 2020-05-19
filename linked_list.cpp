#include <iostream>
#include <iomanip>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

/*int main()
{
    cout << "Hello world!" << endl;
    return 0;
}*/
struct node{
int data;
node * next;
};
node * head=NULL;
/*node* INSERT(node * head, int data)
{
    node* newn=new node();
    newn->data=data;
    newn->next=NULL;
    if(head==NULL)
        head=newn;
    while(head!=NULL)
        head=head->next;
    head->next=newn;
    return head;
}*/
void * INSERT(int data)
{
    node * temp=head;
    node * newN=new node();
    newN->next=NULL;
    newN->data=data;
    if(head==NULL)
        head=newN;
        else
        {
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newN;
        }
}

void print(node * head)
{
    if(head==NULL)
        return;
    else
    {
        cout<<head->data<<endl;
        print(head->next);
    }
}
void reverseprint(node * head)
{
    if(head==NULL)
        return;
    reverseprint(head->next);
    cout<<head->data<<endl;
}
bool has_cycle(node* head) {
node* temp=head;
while(temp)
{
    node* temp1=temp->next;
    while(temp1)
    {
        if(temp==temp1->next)
            {
                cout<<"sfd";
                return true;
            }
        else
        temp1=temp1->next;
    }
        cout<<"123";
    temp=temp->next;
}
return false;
cout<<"d";
}
int sumi(int a[3][3])
{
    int sum=a[1][1];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==0 || i==2)
            sum+=a[i][j];
        }
    }
    return sum;
}
int large(int sum[16])
{
    int max=sum[0];
    for(int i=1;i<16;i++)
    {
        if(sum[i]>max)
        {
            max=sum[i];
        }
    }
    return max;
}
// Complete the hourglassSum function below.
int hourglassSum(int arr[6][6]) {
int a[3][3],sum[16];
for(int i=0;i<6;i++)
{
    for(int j=0;j<6;j++)
    {
        for(int k=0;k<16;k++)
        {
            for(int n=i;n<i+3;n++)
            {
                for(int m=j;m<j+3;m++)
                {
                    a[n][m]=arr[i][j];
                }
            }
            sum[k]=sumi(a);
        }
    }
}
int max=large(sum);
return max;

}
void prin(stack<char> s,int k)
{
    int i=0;
    string w;
    while(!s.empty())
    {
        w[i]=s.top();
        s.pop();
        i++;
    }
    cout<<w[i-k];
}
int length(string w)
{
    int i=0;
    while(w[i]!='\0')
    {
        i++;
    }
    return i;
}
void remov(stack<char> s,int k,char p[50])
{
    for(int i=0;i<k;i++)
    {
        p[k-i-1]=s.top();
        s.pop();
    }
}
bool prime(int n)
{
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
            c+=1;
    }
    if(c<=2)
        return true;
    else
        return false;
}
int getprime(int n)
 {
     int t=0,i=2;
     while(t<n)
     {
         if(prime(i))
         {
             i++;
             t++;
         }
         else
            i++;
     }
     return i-1;
 }
 void Swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{
    /*int n;
    cout<<"enter no. of items";
    cin>>n;
   // cin.ignore(numeric_limits<streamsize>::max(),'\n');
    node *list=NULL;
    for(int i=0;i<n;i++)
    {
        int item;
        cout<<"enter item no."<<i;
        cin>>item;
        node *n=INSERT(list,item);
        list=n;
    }*/
   /* node * temp3=head;
    node * temp=head;
    node * temp1=head;
    int n=2;
    INSERT(2);
    INSERT(3);
    INSERT(8);
    INSERT(6);
*/
    /*while(n>0)
    {
        temp=temp->next;
        n=n-1;
    }
  /* while(temp1!=NULL)
        temp1=temp1->next;
        temp1->next=temp;

      /*  while(temp3->next!=NULL)
        {
            cout<<temp3->data;
            temp3=temp3->next;
        }*/
  //print(head);
   //reverseprint(head);
   //has_cycle(head);
   /*double g=4.0;
   cout<<fixed<<setprecision(1)<<g;*/
//string h;
   //getline(cin,h);
   //cout<<h;
  /* int arr[6][6]={{1,1,1,0,0,0,},{0,1,0,0,0,0,},{1,1,1,0,0,0,},{0,0,2,4,4,0,},{0,0,0,2,0,0,},{0,0,1,2,4,0,}};
   int x=hourglassSum(arr);
   cout<<x;*/
  /* int i=0,j=0;
   stack<char> s;
   string w;
  char p[50];
   getline(cin,w);*/
   /*char w[50];
   cin>>w;
   while(1)
   {
        s.push(w[i]);
        i++;
        if(w[i]=='\n')
            break;
   }*/
   /*while(w[i]!='\0')
   {
       s.push(w[i]);
       i++;
   }*/
  // p=remov(s,2);
  // s.push(w);
  //cout<<s.top();
// prin(s,3);
   // remov(s,2,p);
 //cout<<p;

 //cout<<w[2];
  /*while(!s.empty())
    {
        p[j]=s.top();
        s.pop();
        j++;
    }*/
//cout<<p;
//cout<<getprime(4);
//char i=2;
//cout<<bitset<32>(i);
int a,b;
cin>>a>>b;
Swap(a,b);
cout<<a<<b;
    return 0;
}
