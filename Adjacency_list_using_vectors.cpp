#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        vector<int> g[v];
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=0;i<v;i++)
        {
            cout<<i<<"-> ";
            int j=0;
            for(j=0;j<g[i].size()-1;j++)
            {
                cout<<g[i][j]<<"-> ";
            }
            cout<<g[i][j]<<endl;
        }
    }
    return 0;
}
