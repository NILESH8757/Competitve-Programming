// problem: http://www.spoj.com/problems/EZDIJKST/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
#define inf 0x3f3f3f3f
typedef pair<int,int> pp;
vector<vector<pp > > adj;
int d[MAXN],n;
void dijkstra(int v)
{
    memset(d,inf,sizeof(d));
    d[v] = 0;
    int u;
    priority_queue<pp,vector<pp >, greater<pp > > pq;
   
    pq.push({d[v], v});
    
    while(!pq.empty())
    {
       u = pq.top().second;
       pq.pop();
    
       for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
        if(d[p.first] > d[u] + p.second)
        {
          d[p.first] = d[u] + p.second;
          pq.push({d[p.first], p.first});
        }
   }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
   int e,i,w,x,y,t,st,des;
   cin>>t;
   while(t--){
       
   cin>>n>>e; //no. of nodes & no. of edges
   adj.clear();
   adj.resize(n + 2);
   for(i=0;i<e;i++)
    {
      cin>>x>>y>>w;
      adj[x].push_back({y,w});
    }
    cin>>st>>des;
    dijkstra(st);
    if(d[des]==inf)
    cout<<"NO\n";
    else
    cout<<d[des]<<endl;
   }
    return 0;
}

-------------------------------------------------------------------------------------------------------------------
    // dijkstra for dense graph. O(n^2) complexity. source : cp-algorithms.com
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) 
{
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> vis(n, false);

    d[s] = 0;

    for(int i = 0; i < n; i++) 
    {
        int v = -1;
        
        for (int j = 0; j < n; j++) 
        {
          if(!vis[j] && (v == -1 || d[j] < d[v]))
            v = j;
        }

        if(d[v] == INF)
            break;

        vis[v] = true;
        for(auto edge : adj[v]) 
        {
            int to = edge.first;
            int len = edge.second;

            if(d[v] + len < d[to]) 
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
