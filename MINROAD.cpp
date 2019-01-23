#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct data
{
    long long kc,id;
};
data d[300001];
bool cmp(data x,data b)
{
    return (x.kc<b.kc);
}
long long n,a,b;
bool tinh(long long t)
{
    long long i,d1=0,d2=0,dau=1;
    for (i=1;i<=n;i++)
    {
        if (d[i].id==1) d1++;
        else d2++;
        while (d[i].kc-d[dau].kc>t)
        {
            if (d[dau].id==1) d1--;
            else d2--;
            dau++;
        }
        if (d1>=a && d2>=b) return true;
    }
    return false;
}
int main()
{
    long long i,dau,c,g,vt=-1;
    ifstream fi ("MINROAD.inp");
    ofstream fo ("MINROAD.out");
    fi >>n>>a>>b;
    for (i=1;i<=n;i++) fi >>d[i].kc>>d[i].id;
    sort(d+1,d+1+n,cmp);
    dau=1;
    c=1e9;
    do
    {
        g=(dau+c)/2;
        if (tinh(g))
        {
            vt=g;
            c=g-1;
        }
        else dau=g+1;
    }while (dau<=c);
    fo <<vt;
    return 0;
}
