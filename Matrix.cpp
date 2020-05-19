#include <iostream>

using namespace std;
struct matrix
{
    int *a;
    int n;
    matrix()
    {
        a=new int[n];
    }
};
void set_diagonal(matrix *m,int i, int j,int x)
{
    if(i==j)
    {
        m->a[i]=x;
    }
}
int get_diagonal(matrix *m,int i, int j, int x)
{
    if(i==j)
        return m->a[i];
    else
        return 0;
}
void disp(matrix m)
{
    for(int i=0;i<m.n;i++)
    {
        for(int j=0;j<m.n;j++)
        {
            if(i==j)
            cout<<" "<< m.a[i]<<" ";
            else
                cout<<" 0 ";
        }
        cout<<endl;
    }
}
int main()
{
    matrix m;
    m.n=4;
    set_diagonal(&m,0,0,1);
    set_diagonal(&m,1,1,2);
    set_diagonal(&m,2,2,3);
    set_diagonal(&m,3,3,1);
    disp(m);
    return 0;
}
