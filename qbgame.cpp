#include <iostream>
#include <stdio.h>
using namespace std;
long long a[60][10005];
long long f[10005][60],n;
long long state,x,ma;
long long res;
int get(int x,int i)
{
    return (x>>i)&1;
}
void off(int x,int i)
{
    x=x&(!(1<<i));
}
void on(int x,int i)
{
    x=x|(1<<i);
}
long long value(int x,int j)
{
    long long res=0;
    for(int i=0;i<8;i++)
    {
      //  cout<<get(x,i)<"\n";
        if(get(x,i)==1)
        {
            res+=a[i+1][j];
        }
    }
    return res;
}
int s[]={0,1,2,4,5,8,9,10,16,17,18,20,21,32,33,34,36,37,40,41,42,64,65,66,68,69,72,73,74,80,81,82,84,85,128,129,130,132,133,136,137,138,144,145,146,148,149,160,161,162,164,165,168,169,170};
int main()
{       //55
    freopen("test.inp","r",stdin);
    res=-1e9;
    res=2*res;
    cin>>n;
    for(int i=1;i<=8;i++)
    for(int j=1;j<=n;j++)
    {
        cin>>a[i][j];
        if(res<a[i][j]) res=a[i][j];
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<55;j++)
        {
            ma=0;
            state=s[j];
            x=value(s[j],i);
          //  cout<<" "<<s[j]<<" "<<i<<" "<<x<<"\n";
            for(int k=0;k<55;k++)
            {
                int tem=state&s[k];
                if(tem==0 && f[i-1][k]+x>ma)
                ma=f[i-1][k]+x;
            }
            f[i][j]=ma;
            if(res<0)   //TH toan bo so deu am
            {
                if(f[i][j]>res && f[i][j]!=0) res=f[i][j];
            }
            else if(f[i][j]>res) res=f[i][j];
        }

    cout<<res;
}
