const int N = 2002;
vector<int> g[N];
int n;
// using bfs
bool bipartite_check()
{
     vector<int> side(n, -1); // if bipartite, then partition vertex set into two disjoint sets 
                              // having side == 0 & side == 1
     bool is_bipartite = true;
 
     for(int i = 0; i < n; i++)
     {
        if(side[i] == -1)
        {
            queue<int> q;
            q.push(i);
            side[i] = 0;
            
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
 
                for(int v : g[u])
                {
                    if(side[v] == -1)
                    {
                        side[v] = side[u] ^ 1;
                        q.push(v);
                    }
                    else
                        is_bipartite &= (side[v] != side[u]);
                }
 
                if(!is_bipartite)
                    break;
            }
        }
        if(!is_bipartite)
            break;
     }
     
     return is_bipartite;
}

// problem 1 : BUGLIFE (spoj)
// problem 2 : https://codeforces.com/problemset/problem/687/A
