#include<bits/stdc++.h>
 using namespace std;

#define  int  long long
#define  endl  '\n'
const int mod = 1e9 + 7;

// kruskal's MST
// problem : https://www.spoj.com/problems/MST/
const int N = 10002;
int par[N], sz[N], n;
vector<int> mst[N]; // to store tree.

void init()
{
   for(int i = 1; i <= n; i++)
   {
      par[i] = i;
      sz[i] = 1;
   }
}

int getId(int x)
{
  if(par[x] == x)
    return x;
  return getId(par[x]);
}

void unite(int x, int y)
{
   int px = getId(x);
   int py = getId(y);

   if(px == py) 
      return;

   if(sz[px] < sz[py])
   {
      swap(px, py);
      swap(x, y);
   }

   sz[px] += sz[py];
   par[py] = px;
}

void dfs(int u, int par = -1) // to print nodes in mst
{
   cout << u << ' ';
   for(int v : mst[u])
   {
      if(v == par) continue;
      dfs(v, u);
   }
}

int32_t main()
{ 
 
    int m, u, v, w, start = -1;
    cin >> n >> m;
    
    vector<pair<int, pair<int, int > > > edg;

    for(int i = 0; i < m; i++)
    {
       cin >> u >> v >> w;
       edg.push_back({w, {u, v}});
    }

    sort(edg.begin(), edg.end());
    init();
    int cost = 0;

    for(auto it : edg)
    {
       u = it.second.first;
       v = it.second.second;
       w = it.first;

       int pu = getId(u);
       int pv = getId(v);

       if(pu == pv)
         continue;

       cost += w;
       unite(u, v);

       mst[u].push_back(v);
       mst[v].push_back(u);

       if(start == -1)
        start = u;
    }

    cout << cost << endl;

    //dfs(start);
  return 0;
}
