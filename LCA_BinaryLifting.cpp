//source:https://github.com/rachitiitr/DataStructures-Algorithms/blob/master/dp-on-tree-type-c-LCA.cpp
#include<bits/stdc++.h>
 using namespace std;

#define FIO                     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mod                     1000000007
#define eps                     1e-9
#define setbits                 __builtin_popcount
#define gcd                     __gcd
#define rep(i,a,b)              for(int i=a;i<=b;i++)
#define repr(i,b,a)             for(int i=b;i>=a;i--)
#define forn(i,n)               for(int i=0;i<n;i++)
#define all(a)                  a.begin(), a.end()
#define in(a,b)                 ( (b).find(a) != (b).end())
#define pb                      push_back
#define fill(a,v)               memset(a, v, sizeof(a))
#define endl                    "\n"
#define ff                      first
#define ss                      second
#define mp                      make_pair
#define minin(a)                *min_element (all(a))
#define maxin(a)                *max_element(all(a))
#define asort(c)                sort(all(c))
#define dsort(c)                sort(all(c), greater<int>()) 
#define PI                      3.14159265358979323846
#define int                     long long
typedef  vector<int>                 vi;
typedef  pair<int, int>              ii;
typedef  vector<ii>                 vii;
typedef  set<int>                    si;
typedef  map<int, int>              mii;
typedef  long double                ld;

const int N=2e5+5;
const int LG=20;

vi adj[N];
int lvl[N];
int P[N][LG];

void dfs(int v,int par)
{
   lvl[v]=1+lvl[par];
   P[v][0]=par;

   for(auto u: adj[v])
   {
      if(u!=par)
        dfs(u,v);
   }
}

int lca(int u,int v)
{
  int lg;
  if(lvl[u]<lvl[v])
    swap(u,v);

  for(lg=0; (1<<lg) <= lvl[u]; lg++);

  lg--;

  repr(i,lg,0)
  {
    if(lvl[u] - (1<<i) >= lvl[v])
      u=P[u][i];
  }

  if(u==v)
    return u;

  repr(i,lg,0)
  {
    if(P[u][i]!=-1 && P[u][i]!=P[v][i])
    {
      u=P[u][i];
      v=P[v][i];
    }
  }

  return P[u][0];
}

int dis(int u,int v)
{
  int w=lca(u,v);

  return lvl[u]+lvl[v] - 2*lvl[w];
}
int32_t main()
{
  FIO
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
  #endif
  
  int n,q,r,x,y;
 
    cin>>n;
    forn(i,n+1)
     adj[i].clear();

    forn(i,n-1)
    {
       cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    memset(P,-1, sizeof(P));
    memset(lvl,0,sizeof(lvl));
    lvl[0]=-1;

    dfs(1,0);

    rep(i,1,LG-1)
    {
      rep(j,1,n)
      {
        if(P[j][i-1]!=-1)
          P[j][i]=P[P[j][i-1]][i-1];
      }
    }
    
    cin>>q;

    while(q--)
    {
      cin>>r>>x>>y;
      int mx=1e9;
      int ans;
      
      int w=lca(r,x),d;
      d=dis(w,r)+dis(w,x)+dis(w,y);
      if(d<mx)
      {
        mx=d;
        ans=w;
      }
      w=lca(r,y);
      d=dis(w,r)+dis(w,x)+dis(w,y);
      if(d<mx)
      {
        mx=d;
        ans=w;
      }
      w=lca(x,y);
      d=dis(w,r)+dis(w,x)+dis(w,y);
      if(d<mx)
      {
       // mx=d;
        ans=w;
      }
      cout<<ans<<endl;
    }


  return 0;
}  

//problem link: https://www.codechef.com/problems/TALCA
