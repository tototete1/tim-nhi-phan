#include <iostream>
#include <fstream>
#include <algorithm>
#define ll long long
using namespace std;
long long n,k;
long long a[1000001];
ll giao(ll x)
{
    int day=1,j=0,h=0,i;
    for (i=1;i<=n;i++)
    {
        j++;
        if (a[i]<day)
        {
            h++;
            j--;
        }
        if (j==x)
        {
            day++;
            j=0;
        }
    }
    return h;
}
int main()
{
    long long d,c,g,i,vt;
    ifstream fi ("MILK.inp");
    ofstream fo ("MILK.out");
    fi >>n>>k;
    for (i=1;i<=n;i++) fi >>a[i];
    sort(a+1,a+1+n);
    fo <<giao(k)<<endl;
    d=1;
    c=1e18;
    do
    {
        g=(d+c)/2;
        if (giao(g)==0)
        {
            vt=g;
            c=g-1;
        }
        else d=g+1;
    }while (d<=c);
    fo <<vt;
    return 0;
}
