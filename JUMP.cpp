#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
long long a[100001],vt[100001],ll[100001];
long long n,p;
void ss(long long l,long long r)
{
    long long i=l,j=r,x=a[(l+r)/2];
    while (i<=j)
    {
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            swap(vt[i],vt[j]);
            i++;j--;
        }
    }
    if (l<j) ss(l,j);
    if (i<r) ss(i,r);
}
int main()
{
    long long i;
    long long d,c,g,ans=-1,vt1;
    ifstream fi ("JUMP.inp");
    ofstream fo ("JUMP.out");
    fi >>n>>p;
    for (i=1;i<=n;i++)
    {
        fi >>a[i];
        vt[i]=i;
        ll[i]=a[i];
    }
    ss(1,n);
    for (i=n;i>=2;i--) vt[i-1]=max(vt[i-1],vt[i]);
    for (i=1;i<=n;i++)
    {
        d=i;
        c=n;
        vt1=0;
        do
        {
            g=(d+c)/2;
            if (a[g]-ll[i]>=p)
            {
                vt1=g;
                c=g-1;
            }
            else d=g+1;
        }while(d<=c);
        if (vt1>0) ans=max(vt[vt1]-i,ans);
    }
    if (ans>0) fo <<ans;
    else fo <<0;
    return 0;
}
