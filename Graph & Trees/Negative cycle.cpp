// resource : https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html

#include<bits/stdc++.h>
#define int long long
 using namespace std;
 
struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1e15;

void solve()
{
    vector<int> d(n + 1, INF);
    vector<int> p(n + 1, -1);
    int x;
    d[1] = 0;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }

        reverse(cycle.begin(), cycle.end());

        cout << "YES" << nl;
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}

int32_t main() 
{
  cin >> n >> m; // no. of nodes, no. of edges
  edges.resize(m);

  for(int i = 0; i < m; i++){
     cin >> edges[i].a >> edges[i].b >> edges[i].cost;
  }

  solve();

  return 0;
}

// problem : https://cses.fi/problemset/result/1045434/
