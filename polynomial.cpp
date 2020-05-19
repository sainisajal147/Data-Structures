#include <iostream>
#include<math.h>
using namespace std;
struct term
{
    int coef;
    int exp;
};
struct poly
{
    int n;
    term *t;
};
void get_poly(poly *p)
{
    cout<<"enter the no. of terms\n";
    cin>>p->n;
    p->t=new term[p->n];
    cout<<"enter the coefficients and exponents:\n";
    for(int i=0;i<p->n;i++)
    {
        cin>>p->t[i].coef>>p->t[i].exp;
    }
}
int disp_val(poly p,int x)
{
    int sum=0;
    for(int i=0;i<p.n;i++)
    {
        sum+=p.t[i].coef*pow(x,p.t[i].exp);
    }
    return sum;
}
int main()
{
    poly p;
    get_poly(&p);
    cout<<disp_val(p,0)<<endl;
    cout<<disp_val(p,1)<<endl;
    return 0;
}
