
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
#define fill(a,v)               memset(a, v, sizeof a)
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
typedef  long double                 ld;

const int N=2e5+5;
vi adj[N];
bool vis[N];

void bfs(int u)
{
    queue<int> q;
 
    q.push(u);
    vis[u] = true;
 
    while (!q.empty()) 
    {
        int v = q.front();
        q.pop();
 
        //cout << v << " ";
 
        // Enqueue all adjacent of v and mark them visited 
        for(auto node: adj[v])
        {
            if (!vis[node]) {
                q.push(node);
                vis[node] = true;
            }
        }
    }
}

int32_t main()
{ 
  int n,m,x,y;
  cin>>n>>m;

  forn(i,m)
  {
  	cin>>x>>y;
  	adj[x].pb(y);
  	adj[y].pb(x);
  }

  bfs(1);
  
  return 0;
}  
