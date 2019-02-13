#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char s[1000001];
ifstream fi ("VUOTSONG.inp");
ofstream fo ("VUOTSONG.out");
long long n,i;
long long R[1000001],L[1000001];
int main()
{
    fi.getline(s,1000001);
    n=strlen(s);
    R[0]=1;
    for (i=0;i<n;i++)
    {
        if (s[i]=='L')
        {
            L[i+1]=min(L[i]+1,R[i]+1);
            R[i+1]=min(R[i],L[i]+1);
        }
        if (s[i]=='R')
        {
            L[i+1]=min(L[i],R[i]+1);
            R[i+1]=min(R[i]+1,L[i]+1);
        }
        if (s[i]=='B')
        {
            L[i+1]=min(L[i]+1,R[i]+2);
            R[i+1]=min(R[i]+1,L[i]+2);
        }

    }
    fo <<R[n];
    return 0;
}
