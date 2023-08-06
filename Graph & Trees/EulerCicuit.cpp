
// Euler circuit on undirected graph (Solution of problem: https://cses.fi/problemset/task/1691/ ) 
// refer book: https://cses.fi/book/book.pdf   for more info on euler path/circuit on directed/undirected graphs
const int N = 1e5 + 5;
set<int> adj[N];
vector<int> path;
int degree[N], n;

void dfs(int node){
	while(!adj[node].empty()){
		int next_node = *adj[node].begin();
		adj[node].erase(adj[node].begin());
		adj[next_node].erase(adj[next_node].find(node));
		dfs(next_node);
	}
	path.push_back(node);
}
int main() {
  int m, a, b;

  cin >> n >> m;

  for(int i = 0; i < m; i++){
  	 cin >> a >> b;
  	 degree[a]++;
  	 degree[b]++;
  	 adj[a].insert(b);
  	 adj[b].insert(a);
  }

  bool impossible = false;

  for(int i = 1; i <= n; i++){
  	impossible |= (degree[i] & 1);
  }

  if(impossible)
  	 return cout << "IMPOSSIBLE", 0;

  dfs(1);
  
  if(path.size() <= m){
  	 cout << "IMPOSSIBLE";
  } else{
  	for(int node: path){
  		cout << node << ' ';
  	}
  }
 return 0;
}
// end of euler circut code for undirected graph. Tweak slightliy to get euler path.
