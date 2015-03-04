#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
queue<int> q;
priority_queue<ii,vector<ii>,greater<ii> > pq;
int INF=1e9;
int dist[30020],distc[30020],countx[30020],countn[30020];
vector<vii> a;
int n,m,k;

int dijkstra()
{
    for(int i = 1;i <= n;i++)   {countx[i]=0;dist[i]=INF;}
    dist[1]=0;
        countx[1]=1;

    pq.push(ii(0,1));
    while(!pq.empty())
    {
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(d == dist[u])
        {
            for(int i = 0;i < a[u].size();i++)
            {
                ii v = a[u][i];
                    if(dist[u] + v.second < dist[v.first])
                    {
                        dist[v.first] = dist[u] + v.second;
                        pq.push(ii(dist[v.first],v.first));
                        countx[v.first]=countx[u];
                    }
                    else if(dist[u] + v.second == dist[v.first])    countx[v.first]+=countx[u];
            }
        }
    }

}
int dijkstrac()
{
    for(int i = 1;i <= n;i++)   {countn[i]=0;distc[i]=INF;}
    distc[n]=0;
    countn[n]=1;
    pq.push(ii(0,n));
    while(!pq.empty())
    {
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(d == distc[u])
        {
            for(int i = 0;i < a[u].size();i++)
            {
                ii v = a[u][i];
                    if(distc[u] + v.second < distc[v.first])
                    {
                        distc[v.first] = distc[u] + v.second;
                        pq.push(ii(distc[v.first],v.first));
                        countn[v.first]=countn[u];
                    }
                    else if(distc[u] + v.second == distc[v.first])    countn[v.first]+=countn[u];

            }
        }
    }

}

int main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d%d",&n,&m);
    a.assign(n+2,vii());
    for(int i = 1;i <= m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    dijkstra();
    dijkstrac();
    int res=0;
    for(int i=1;i<=n;i++)
    {
    //printf("%d %d %d %d %d\n",i,dist[i],distc[i],countx[i],countn[i]);
    if((dist[i]+distc[i]!=dist[n]) || (dist[i]+distc[i]==dist[n] && countx[i]*countn[i]!=countx[n]))   {++res; q.push(i);}
    }
    printf("%d\n",res);
    while(!q.empty())   {int temp=q.front();q.pop();printf("%d\n",temp);}
}
