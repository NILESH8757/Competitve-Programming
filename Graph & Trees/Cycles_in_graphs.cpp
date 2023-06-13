//Find cycle in directed graph. Problem: https://cses.fi/problemset/task/1678
const int N = 1E5 + 5;
int n;
vector<int> adj[N];
vector<int> color;
vector<int> parent;
int cycle_start, cycle_end;
 
bool dfs(int v, int par) { // passing vertex and its parent vertex
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u, parent[u]))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}
 
void find_cycle() {
    color.resize(n + 1, 0);
    parent.resize(n + 1, -1);
    cycle_start = -1;
 
    for (int v = 1; v <= n; v++) {
        if (color[v] == 0 && dfs(v, parent[v]))
            break;
    }
 
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
 
        cout << cycle.size() << nl;
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}
 
int32_t main() 
{
  int m;
  cin >> n >> m;
 
  for(int i = 0; i < m; i++) {
     int u, v;
     cin >> u >> v;
     adj[u].push_back(v);
  }
 
  find_cycle();
 
  return 0;
}

/********************************************************************************************************************/
// Finding cycle in undirected graph. problem: https://cses.fi/problemset/task/1669/

const int N = 1E5 + 3;
int cnt;
vector<int> g[N];
bool vis[N];
int par[N];
 
void printCycle(int st, int en){
   vector<int> path;
   path.push_back(st);
 
   while(en != st){
      path.push_back(en);
      en = par[en];
   }
 
   path.push_back(st);
   cout << path.size() << endl;
   for(int nodes : path)
      cout << nodes << ' ';
 
}

void dfs(int node, int p){
 
   par[node] = p;
   vis[node] = 1;
 
   for(int child : g[node]){
      if(child == p) continue;
      if(!vis[child])
         dfs(child, node);
      else{
        printCycle(child, node);
        exit(0);
      }
   }
}
 
int32_t main() 
{
  int n, m;
  cin >> n >> m;
 
  for(int i = 1; i <= n; i++)
      vis[i] = false;
 
  for(int i = 0; i < m; i++){
     int a, b;
     cin >> a >> b;
     g[a].push_back(b);
     g[b].push_back(a);
  }
  
  for(int i = 1; i <= n; i++){
     if(!vis[i]){
        dfs(i, 0);
     }
  }
  cout << "IMPOSSIBLE";
  return 0;
}
