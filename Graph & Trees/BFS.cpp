
#include<bits/stdc++.h>
 using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
int level[N] // number of level from source node u
int ways[N] // no. of ways to reach from source node u to current node with the shortest path taken
bool vis[N];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = true;
    ways[u] = 1;
 
    while (!q.empty()) {
     
        int v = q.front();
        q.pop();
 
        for(auto node: adj[v]) {
            if (!vis[node]) {
                ways[node] += ways[v];
                level[node] = 1 + level[v];
                q.push(node);
                vis[node] = true;
            } else {
                if(level[v] + 1 == level[node]) {
                    ways[node] += ways[v];
                }
	    }
        }
    }
}
