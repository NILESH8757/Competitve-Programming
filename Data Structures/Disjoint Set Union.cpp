//motivation problem: https://www.codechef.com/problems/DISHOWN

// following code is the soln of :  https://cses.fi/problemset/task/1676

#include<bits/stdc++.h>
#define int long long
#define nl '\n'
 using namespace std;

const int N = 1E5 + 5;

int sz[N], par[N], n, comp, maxsize;

void init(){
   comp = n;
   for(int i = 1; i <= n; i++){
       sz[i] = 1;
       par[i] = i;
   }
}

int getParent(int x){
   return x == par[x] ? x : par[x] = getParent(par[x]);
}

void Unite(int a, int b){
    int pa = getParent(a);
    int pb = getParent(b);
    if(pa == pb) return;

    comp--;

    if(sz[pa] < sz[pb]){
       swap(pa, pb);
    }

    sz[pa] += sz[pb];
    sz[pb] = 0;
    par[pb] = pa;
    maxsize = max(maxsize, sz[pa]);
}

int32_t main() 
{
  int m;
  cin >> n >> m;
  
  init();

  for(int i = 0; i < m; i++){
     int u, v;
     cin >> u >> v;
     Unite(u, v);
     cout << comp << ' ' << maxsize << nl;
  }

  return 0;
}


// another problem : https://cses.fi/problemset/result/1045648/
// soln. : https://cses.fi/paste/808deed8cf7122c8ff490/
