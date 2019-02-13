#include <iostream>
#include <fstream>
using namespace std;
ifstream fi ("SOTRANG.INP");
ofstream fo ("SOTRANG.OUT");
long long n,i,t,x,dem[11];
int main()
{
    fi >>n;
    for (i=1;i<=n;i++)
    {
        t=i;
        while (t>0)
        {
            x=t%10;
            t=t/10;
            dem[x]++;
        }
    }
    for (i=0;i<=9;i++)
    {
        fo <<i<<" "<<dem[i]<<endl;
    }
    return 0;
}
