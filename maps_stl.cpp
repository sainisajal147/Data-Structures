#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include<string>
#include<unordered_map>
using namespace std;


int main() {
    map<char,int> m;
    unordered_map<char, int> u;
    string s="sajal saini is the master";
    for(int i=0;i<s.size();i++)
    {
        u[s[i]]++;
    }
    for(int i=0;i<s.size();i++)
    {
        m[s[i]]++;
    }
    unordered_map<char, int>::iterator p=u.begin();
    while(p!=u.end())
    {
        cout<<p->first<<" "<<p->second<<endl;
        p++;
    }
    cout<<"now the values for the map:"<<endl;
    map<char, int>::iterator q=m.begin();
    while(q!=m.end())
    {
        cout<<q->first<<" "<<q->second<<endl;
        q++;
    }
    return 0;
}
