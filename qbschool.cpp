#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<long long,long long> ii;
typedef vector<long long> vi;
typedef vector<ii> vii;
#define INF 1e9
vector<vii> adj;
priority_queue <ii, vector<ii>, greater<ii> > pq;
vi dist;
long long n,m,cnt[6005];
void dijkstra()
{
    dist.assign(n+1,INF);
    dist[1]=0;
    pq.push(ii(0,1));
    while(!pq.empty())
    {
        ii front=pq.top();
        pq.pop();
        int u=front.second;
        int d=front.first;
        if(d==dist[u])
        {
            for(int j=0;j<adj[u].size();j++)
            {
                ii v=adj[u][j];
                if(dist[u]+v.second<dist[v.first])
                {
                    dist[v.first]=dist[u]+v.second;
                    pq.push(ii(dist[v.first],v.first));
                    cnt[v.first]=cnt[u];
                }
                else if(dist[u]+v.second==dist[v.first]) cnt[v.first]+=cnt[u];
            }
        }
    }
}
int main()
{
    long long k,u,v,l;
    cin>>n>>m;
    adj.assign(n+1,vii());
    cnt[1]=1;
    for(int i=1;i<=m;i++)
    {
        cin>>k>>u>>v>>l;
        adj[u].push_back(ii(v,l));
        if(k==2) adj[v].push_back(ii(u,l));
    }
    dijkstra();
    cout<<dist[n]<<" "<<cnt[n];
}
