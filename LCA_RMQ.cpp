//note : 1 - based indexing throughout.
// problem : https://www.spoj.com/problems/LCA/

const int N = 1002;
vector<int> g[N], segtree(8*N), euler, height(N);

void dfs(int node, int ht = 0, int par = 0)
{
   euler.push_back(node);
   height[node] = ht;

   for(int u : g[node])
   {
   	  if(u != par)
   	  {
   	  	 dfs(u, ht + 1, node);
   	  	 euler.push_back(node);
   	  }
   }
}

void build(int node, int st, int en)
{
   if(st == en)
   {
   	  segtree[node] = euler[st];
   	  return;
   }

   int mid = (st + en) >> 1;
   build(node << 1, st, mid);
   build(node << 1 | 1, mid + 1, en);
   segtree[node] = height[segtree[node << 1]] < height[segtree[node << 1 | 1]]
                   ? segtree[node << 1] : segtree[node << 1 | 1];
}

int query(int node, int st, int en, int l, int r)
{
   if(l > en or r < st)
   	return 0;

   if(l <= st && en <= r)
   	return segtree[node];

   int mid = (st + en) >> 1;
   int left = query(node << 1, st, mid, l, r);
   int right = query(node << 1 | 1, mid + 1, en, l, r);

   return height[left] < height[right] ? left : right;
}

int32_t main()
{ 
  int tests;

  cin >> tests;

  for(int tc = 1; tc <= tests; tc++)
  {
  	  euler.clear();
	  euler.push_back(0); // dummy data for 1-based indexing;
	  height[0] = INT_MAX; // dummy height

      
	  int n;
	  cin >> n;

          for(int i = 1; i <= n; i++)
      	   g[i].clear();

	  for(int i = 1; i <= n; i++)
	  {
	  	 int ch, id;
	  	 cin >> ch;

	  	 while(ch--)
	  	 {
	  	 	cin >> id;
	  	 	g[i].push_back(id);
	  	 	g[id].push_back(i);
	  	 }
	  }

	  dfs(1);
	  vector<int> oc(n + 1, -1);
	  
	  for(int i = 1; i < euler.size(); i++)
	  {
	  	 if(oc[euler[i]] == -1)
	  	 	oc[euler[i]] = i;
	  }
	  
	  segtree.clear();
	  build(1, 1, (int)euler.size());

	  int q, u, v;
	  cin >> q;

	  cout << "Case " << tc <<":\n";
	  while(q--)
	  {
	     cin >> u >> v;
	     int l = oc[u], r = oc[v];
	     if(l > r)
	     	swap(l, r);

	     int ans = query(1, 1, (int)euler.size(), l , r);
	     cout << ans << endl;
	  }

  }
  return 0;
}
