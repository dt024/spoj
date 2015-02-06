#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
int par[500];
int init(int x)
{
    for(int i=1;i<=x;i++) par[i]=i;
}
int findset(int x)
{
    if(par[x]==x) return x;
    return par[x]=findset(par[x]);
}
int join(int x,int y) {par[findset(x)]=par[findset(y)];}
bool sameset(int x,int y) {return findset(x)==findset(y);}
vector<pair<int,ii> > edge;
int n;
int kruskal()
{
    int mst=0;
    init(n);
    for(int i=0;i<edge.size();i++)
    {
        pair<int, ii> front = edge[i];
        if(!sameset(front.second.first,front.second.second))
        {
            join(front.second.first,front.second.second);
            mst+=front.first;
        }
    }
    return mst;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u;
        cin>>u;
        edge.push_back(make_pair(u,ii(n+1,i)));
    }

    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        int a;
        cin>>a;
        edge.push_back(make_pair(a,ii(i,j)));
    }
    sort(edge.begin(),edge.end());
    cout<<kruskal();
}
