#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
long long n,m,a[1000001],d,c,g,vt=-1;
long long chat(long long x)
{
    long long s=0,i;
    for (i=1;i<=n;i++) if (a[i]>x) s=s+a[i]-x;
    return s;
}
int main()
{
    long long i;
    ifstream fi ("PHILAO.inp");
    ofstream fo ("PHILAO.out");
    fi >>n>>m;
    for (i=1;i<=n;i++) fi >>a[i];
    sort(1+a,a+1+n);
    fo <<chat(a[1])<<endl;
    d=0;
    c=a[n];
    do
    {
        g=(d+c)/2;
        if (chat(g)>=m)
        {
            //du=m-chat(a[g]);
            vt=g;
            d=g+1;
        }
        else c=g-1;
    }while (d<=c);
    if (vt!=-1) fo <<vt;
    else fo <<-1;
    return 0;
}
