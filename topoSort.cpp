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
// using bfs
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
