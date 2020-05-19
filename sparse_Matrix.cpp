#include <iostream>

using namespace std;
struct element
{
    int i,j,x;
};
struct sparse
{
    int m,n,num;
    element *e;
};
void get_sparse(sparse *s)
{
    cout<<"enter m,n and number of non zero elements\n";
    cin>>s->m>>s->n>>s->num;
    cout<<"enter elements row by row\n";
    s->e=new element[s->num];
    for(int q=0;q<s->num;q++)
    {
        cin>>s->e[q].i>>s->e[q].j>>s->e[q].x;
    }
}
void disp(sparse s)
{
    int i,j,k=0;
    for(int i=0;i<s.m;i++)
    {
        for(int j=0;j<s.n;j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
                {cout<<s.e[k].x;
                k++;
                }
            else
                cout<<"0";
        }
        cout<<endl;
    }
}
sparse add(sparse a,sparse b)
{
    if(a.m!=b.m || a.n!=b.n)
        cout<<"Error\n";
    else
    {
        sparse c;
        c.m=a.m;
        c.n=a.n;
        c.num=a.num+b.num;
        c.e=new element[c.num];
        int ai=0,bi=0;
        for(int q=0;q<c.num;q++)
        {
            if(a.e[ai].i<b.e[bi].i)
            {
                c.e[q].i=a.e[ai].i;
                c.e[q].j=a.e[ai].j;
                c.e[q].x=a.e[ai].x;
                ai++;
            }
            else if(a.e[ai].i>b.e[bi].i)
            {
                c.e[q].i=b.e[bi].i;
                c.e[q].j=b.e[bi].j;
                c.e[q].x=b.e[bi].x;
                bi++;
            }
            else if(a.e[ai].i==b.e[bi].i && a.e[ai].j<b.e[bi].j)
            {
                c.e[q].i=a.e[ai].i;
                c.e[q].j=a.e[ai].j;
                c.e[q].x=a.e[ai].x;
                ai++;
            }
            else if(a.e[ai].i==b.e[bi].i && a.e[ai].j>b.e[bi].j)
            {
                c.e[q].i=b.e[bi].i;
                c.e[q].j=b.e[bi].j;
                c.e[q].x=b.e[bi].x;
                bi++;
            }
            else if(a.e[ai].i==b.e[bi].i && a.e[ai].j==b.e[bi].j)
            {
                c.e[q].i=b.e[bi].i+a.e[ai].i;
                c.e[q].j=b.e[bi].j+a.e[ai].j;
                c.e[q].x=b.e[bi].x+a.e[ai].x;
                bi++;
                ai++;
            }
        }
        return c;
    }
}
int main()
{
    sparse a,b,c;
    get_sparse(&a);
    disp(a);
    get_sparse(&b);
    disp(b);
    disp(add(a,b));
    return 0;
}
