// Author : nilesh8757
// 18 Oct.,2017. 214(BH-7),SLIET
/* topological sorting along with longest path in DAGs. Longest path in 
   DAG represent minimum no. of steps to list all vertices in groups. */
 
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int> adj[N];
vector<int> ts; // stores topologically sorted vetices
int indeg[N]; // stores indegree of vertices
int lpt[N];  //lpt[i]=longest path to node i;
int n;
// using bfs also know as Kahn’s algorithm for Topological Sorting
void topologicalSort()
{
	memset(indeg,0,sizeof(indeg));
        memset(lpt,0,sizeof(lpt));
	
	for(int i = 1 ;i <= n; i++)
	{
		for(int j : adj[i])
		{
			indeg[j]++;
		}
	}
	
	queue<int> q; //stores nodes with indegree==0
	
	for(int i = 1; i <= n; i++)
	{
		if(indeg[i] == 0)
		  q.push(i);
	}
	
	while(!q.empty())
	{
		int j = q.front();
		ts.push_back(j) ; 
		q.pop();
		for(int k : adj[j])
		{
			indeg[k]--;
			lpt[k] = max(lpt[k], 1 + lpt[j]);
			if(indeg[k] == 0)
			  q.push(k);
		}
	}
}

int main()
{
	int x, y, e;
	cin >> n >> e;  //no. of nodes & no. of edges

	for(int i = 1; i <= e; i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
	}

	topologicalSort();

	// following loop prints topologically sorted vetices :)
	for(int i = 0; i < ts.size(); i++)
	{
		cout << ts[i] << " ";
	}
	cout << endl;
	for(int i = 1; i <= n; i++)
	{
	       cout << lpt[i] << " ";
	}
 
  return 0;	
}

/***************checking cycle in directed graph using dfs. If cycle is present, topological sorting is not possible ******/
vector<int> color(N);
bool cycle;

void dfs(int u) // checking for acyclicity
{
    color[u] = 1; // mark grey, i.e first time visited.
    for(int v: g[u])
    {
        if(color[v] == 0) // this node's white means still not visited
        {
            dfs(v);
        }
        else if(color[v] == 1) // back edge found!
          cycle = true;
    }
    color[u] = 2; //finally marked black in the last visit to the node.
}

// if it's DAG, find a topological order as given here : https://cp-algorithms.com/graph/topological-sort.html
