// problem : https://www.codechef.com/problems/AVVST
// Updating a node and query for a subtree rooted at node x
// Inspiration : https://discuss.codechef.com/t/a-technique-to-convert-tree-to-a-linear-array-for-efficient-query-processing/9298

#include<bits/stdc++.h>
using namespace std;
const int N = 300000 + 30;
vector<int> g[N];
int in[N];
int out[N];
int segtree[4 * N];
int n, Time;
int a[N];
bool is_prime[N];


void sieve(){

  for(int i = 0; i < N; i++)
     is_prime[i] = true;

  is_prime[0] = is_prime[1] = false;

  for(int i = 2; i < N; i++){
      if(is_prime[i]){
         for(int j = i + i ; j < N; j += i){
            is_prime[j] = false;
         }
      }
  }
}

void dfs(int node, int par)
{
   in[node] = ++Time;
   for(int u : g[node])
   {
      if(u != par)
       dfs(u, node);
   }
   out[node] = Time;
}

void build(int node, int st, int en){
   if(st == en){
       segtree[node] = a[st];
       return;
   }
   int mid = (st + en) >> 1;
   build(node << 1, st, mid);
   build(node << 1 | 1, mid + 1, en);
   segtree[node] = segtree[node << 1] + segtree[node << 1 | 1];
}

void update(int node, int st, int en, int pos, int val)
{
   if(st == en){
      segtree[node] = val;
      return;
   }

   int mid = (st + en) >> 1;
   if(pos <= mid)
     update(node << 1, st, mid, pos, val);
   else
     update(node << 1 | 1, mid + 1,  en, pos, val);

   segtree[node] = segtree[node << 1] + segtree[node << 1 | 1];
}

int query(int node, int st, int en, int l, int r)
{
   if(st > r or en < l or l > r)
    return 0;

   if(l <= st && en <= r)
   {
      return segtree[node];
   }
  
   int mid = (st + en) >> 1;
   int left = query(node << 1, st, mid, l, r);
   int right = query(node << 1 | 1, mid + 1, en, l, r);
   return left + right;
}

int main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif 

  
  sieve();

  int tests;
  cin >> tests;

  while(tests--) {

      int q;

      cin >> n >> q;
      int arr[n + 1];
      for(int i = 1; i <= n; i++){
        cin >> arr[i];
        g[i].clear();
      }

      for(int i = 1; i < n; i++)
      {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
      }

      Time = 0;
      dfs(1, 0);
      
      for(int i = 1; i <= n; i++){
         a[in[i]] = (arr[i] > 0 && is_prime[arr[i]]);
      }
      
      build(1, 1, n);
     
      while(q--)
      {
         int type;
         cin >> type;
         if(type == 1)
         {
           int x, v;
           cin >> x >> v; 
           v = (v > 0 && is_prime[v]);
           update(1, 1, n, in[x], v);
         }
         else
         {
           int x;
           cin >> x;
           int ans = query(1, 1, n, in[x], out[x]);
           cout << ans << "\n";
         }
         
      }
  }
  return 0;
}
