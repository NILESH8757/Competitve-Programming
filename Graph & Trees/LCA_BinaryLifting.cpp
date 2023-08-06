const int LG = 20;
const int N = 2e5 + 5;
int ancestors[N][LG], level[N], n;
vector<int> tree[N];

//dfs is not required in case of finding only Kth parent of a node (obvious from the code)

void dfs(int node, int parent = -1, int lvl = 0) {
  level[node] = lvl;
  ancestors[node][0] = parent;
  for(int child: tree[node]) {
    if(child != parent) {
     		dfs(child, node, lvl + 1);
    }
  }
} 

void preprocess() {
	for(int j = 1; j < LG; j++) {
		  for(int node = 1; node <= n; node++) {
			    int ancestor = ancestors[node][j - 1];
			    if(ancestor == -1)
				     ancestors[node][j] = -1;
			    else
				     ancestors[node][j] = ancestors[ancestor][j - 1];
		  }
	 }
}

int getLCA(int a, int b) {
    if(level[a] <= level[b]) {
    	 swap(a, b);
    }
    int k = level[a] - level[b];
    for(int j = 0; j < LG; j++) {
    	  if((k >> j) & 1){
    		    a = ancestors[a][j];
    	  }
    }
    if(a == b)
    	 return a;
 
    for(int j = LG - 1; j >= 0; j--) {
    	if(ancestors[a][j] != -1 && ancestors[a][j] != ancestors[b][j]) {
    		   a = ancestors[a][j];
    		   b = ancestors[b][j];
    	 }
    }
    return ancestors[a][0];
}

int getDistance(int u, int v) {
	   int lca = getLCA(u, v);
   	return level[u] + level[v] - 2 * level[lca];
}

int getKthAncestor(int x, int k) {
    for(int j = LG - 1; j >= 0; j--) {
    	 if((k >> j) & 1) {
    		  x = ancestors[x][j];
    		  if(x == -1)
    			   return x;
    	 }
    }
    return x;
}
