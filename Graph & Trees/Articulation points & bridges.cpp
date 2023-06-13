// resource 1 : https://cp-algorithms.com/graph/cutpoints.html
// resource 2 : https://www.eecs.wsu.edu/~holder/courses/CptS223/spr08/slides/graphapps.pdf

// problme 1 : https://www.spoj.com/problems/SUBMERGE/ [straightforward Articulation points problem ]
// solution 1 : http://ideone.com/ZQDphD

int timer = 0;
void findCutVertices(int node, int parent, vector<vector<int> > &adj, set<int> &cut_vertices, 
vector<int> &vis, vector<int> &tin, vector<int> &low){
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int children = 0;
    for(int child: adj[node]){
        if(child == parent) continue;
        if(!vis[child]){
            findCutVertices(child, node, adj, cut_vertices, vis, tin, low);
            low[node] = min(low[node], low[child]);
            if(tin[node] <= low[child] && parent != -1){
                cut_vertices.insert(node);
            }
            children++;
        } else{
            low[node] = min(low[node], tin[child]);
        }
    }
    if(children > 1 && parent == -1){
        cut_vertices.insert(node);
    }
}

//-----------------------------------------------------------------------------------------

// resource 3 : https://cp-algorithms.com/graph/bridge-searching.html
// problem 2 : https://www.spoj.com/problems/EC_P/ [ straightforward bridge problem ]
// solution 2 : http://ideone.com/o9S4w5

int timer = 0;
void findBridges(int node, int parent, vector<vector<int> > &adj, vector<pair<int, int> > &bridges, 
vector<int> &vis, vector<int> &tin, vector<int> &low){
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for(int child: adj[node]){
        if(child == parent) continue;
        if(!vis[child]){
            findBridges(child, node, adj, bridges, vis, tin, low);
            low[node] = min(low[node], low[child]);
            // if(tin[node] >= low[child]) //edge (node -> child) is not a bridge 
            //because child can be reached in same or lesser time than current node
            if(tin[node] < low[child]){
                bridges.push_back({min(node, child), max(node, child)}); //its a bridge
            }
        } else{
            low[node] = min(low[node], low[child]);
        }
    }
}
