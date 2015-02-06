#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
vector<vi> adj;
int n,f[1000],rr[1000];
int a[1000];
bool checkv[1000];
    map<long long,int> check;

int main()
{
    cin>>n;
    adj.assign(n+1,vi());
    for(int i=1;i<=n;i++)
        {cin>>a[i]; }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        check[a[i]]=i;
//        name[i]=a[i];
    }
    for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
    {
        if(check[a[i]+a[j]]!=0)
        {
            adj[check[a[i]+a[j]]].push_back(i);
            adj[check[a[j]+a[i]]].push_back(j);
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<i<<">> ";
        for(int j=0;j<adj[i].size();j++) cout<<adj[i][j]<<" ";
        cout<<"\n";
    }*/
    int res=0;
    for(int i=1;i<=n;i++) f[i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        f[i]=max(f[i],f[adj[i][j]]+1);
    }
    for(int i=1;i<=n;i++) res=max(res,f[i]);
    cout<<res;
}
