#include <iostream>
#include <fstream>
using namespace std;
long long n,m;
long long a[100001];
long long tinh(long long x)
{
    long long i,s=0;
    for (i=1;i<=n;i++) s=s+x/a[i];
    return s;
}
int main()
{
    long long i,vt=0,g,d,c;
    ifstream fi ("TUVAN.inp");
    ofstream fo ("TUVAN.out");
    fi >>n>>m;
    for (i=1;i<=n;i++) fi >>a[i];
    d=0;
    c=1e18;
    do
    {
        g=(d+c)/2;
        if (tinh(g)>=m)
        {
            vt=g;
            c=g-1;
        }
        else d=g+1;
    }while (d<=c);
    fo <<vt;
    return 0;
}
