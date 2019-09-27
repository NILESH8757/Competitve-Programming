// problem : https://www.codechef.com/problems/IITK1P10
// Updating a node and query for a subtree rooted at node x
// Inspiration : https://discuss.codechef.com/t/a-technique-to-convert-tree-to-a-linear-array-for-efficient-query-processing/9298

const int N = 100002;
vector<int> g[N];
vector<int> in(N);
vector<int> out(N);
vector<int> tour;
vector<int> a(N), arr(N);
vector<int> segtree(4 * N);
int Time, n;

void dfs(int node, int par  = -1)
{
   in[node] = ++Time;
   tour.push_back(node);

   for(int u : g[node])
   {
      if(u != par)
       dfs(u, node);
   }
   out[node] = Time;
}

void build(int node, int st, int en) // O-index based
{
   if(st == en)
   {
      segtree[node] = (a[st] == 0);
      return;
   }

   int mid = (st + en) >> 1;
   build(node << 1 | 1, st, mid);
   build(node << 1 | 2, mid + 1, en);

   segtree[node] = segtree[node << 1 | 1] + segtree[node << 1 | 2];
}

void update(int node, int st, int en, int pos, int val)
{
   if(st == en)
   {
      a[pos] += val;
      segtree[node] = (a[pos] == 0);
      return;
   }

   int mid = (st + en) >> 1;
   if(pos <= mid)
    update(node << 1 | 1, st, mid, pos, val);
   else
    update(node << 1 | 2, mid + 1,  en, pos, val);

   segtree[node] = segtree[node << 1 | 1] + segtree[node << 1 | 2];
}

int query(int node, int st, int en, int l, int r)
{
   if(st > r or en < l)
    return 0;

   if(l <= st && en <= r)
   {
      return segtree[node];
   }
  
   int mid = (st + en) >> 1;
   int left = query(node << 1 | 1, st, mid, l, r);
   int right = query(node << 1 | 2, mid + 1, en, l, r);
   return left + right;
}

int main()
{ 
  int q;
  cin >> n >> q;

  for(int i = 1; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  for(int i = 0; i < n; i++)
   cin >> arr[i];

  Time = 0;
  dfs(0);
  
  unordered_map<int,int> idx, ridx;
  
  for(int i = 0; i < tour.size(); i++)
  {
    idx[tour[i]] = i;
    ridx[i] = tour[i];
  }
  
  for(int i = 0; i < tour.size(); i++)
  {
     a[i] = arr[ridx[i]];
  }

  build(0, 0, n - 1);
  
  while(q--)
  {
     char type;
     cin >> type;
     if(type == 'Q')
     {
       int x;
       cin >> x;
       --x;
       int l = in[x] - 1;
       int r = out[x] - 1;
    
       if(l > r)
        swap(l, r);

       int ans = query(0, 0, n - 1, l, r);
       cout << ans << endl;
     }
     else
     {
       int x, v;
       cin >> x >> v;
       --x;
       int id = idx[x];

       update(0, 0, n - 1, id, v);
     }
  }
  
  return 0;
}
