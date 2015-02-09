#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int get(int x,int i)    { return (x>>i)&1;}
long long  off(int x,int i)   { return (x &  (~(1 << i)));}
long long on(int x,int i)    { return x|(1<<i); }
long long n,a[20][20],f[20][66000],k,u,b[22],pre;
int main()
{
   // freopen("test.inp","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        cin>>a[i][j];
    long long last=(1<<n)-1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=last;j++) f[i][j]=1e9;
    int temp;
    for(int i=1;i<=n;i++) { temp=(1<<(i-1));   f[i][temp]=0; } /
    for(int state=1;state<=last;state++)
    {
        k=0;
        for(int i=1;i<=n;i++)
        if(get(state,i-1)==1)
        {
                ++k;
                b[k]=i;
        }
        for(int i=1;i<=k;i++)
        {
            u=b[i];
            pre=off(state,b[i]-1);
            for(int j=1;j<=k;j++)
            if(b[i]!=b[j])
            {
                if (f[b[j]][pre]+a[b[j]][u]<f[u][state])
                    f[u][state]=f[b[j]][pre]+a[b[j]][u];
            }
        }
    }
    long long res=2*1e9;
    for(int i=1;i<=n;i++)
    if(f[i][last]<res)  res=f[i][last];
    cout<<res;
}
