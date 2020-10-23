// https://codeforces.com/contest/652/problem/D
// given n segments on a line. There are no ends of some segments that coincide. For each segment find the number of segments it contains.

// https://codeforces.com/blog/entry/43986?#comment-300572

#include <bits/stdc++.h>
 using namespace std;
 
const int N = 4E5 + 5;
struct data {
  int l, r, idx;
};

bool comp(struct data &d1, struct data &d2) {
  return d1.r < d2.r;
};

data arr[N];
int segtree[4 * N], ans[N], MAXN;

void update(int node, int st, int en, int pos){
   if(st == en){
       segtree[node] += 1;
       return;
   }
   int mid = st + en >> 1;
   if(pos <= mid)
     update(node << 1, st, mid, pos);
   else
     update(node << 1 | 1, mid + 1, en, pos);

   segtree[node] = segtree[node << 1] + segtree[node << 1 | 1];
}

int query(int node, int st, int en, int l, int r){
   if(st > r || en < l)
     return 0;
   if(l <= st && en <= r)
     return segtree[node];
   int mid = st + en >> 1;
   int lhs = query(node << 1, st, mid, l, r);
   int rhs = query(node << 1 | 1, mid + 1, en, l, r);
   return lhs + rhs;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  set<int> S;
  map<int, int> id;

  for(int i = 1; i <= n; i++){
     cin >> arr[i].l >> arr[i].r;
     S.insert(arr[i].l);
     S.insert(arr[i].r);
     arr[i].idx = i;
  }

  for(int val : S) 
     id[val] = ++MAXN;

  for(int i = 1; i <= n; i++){
      arr[i].l = id[arr[i].l];
      arr[i].r = id[arr[i].r];
  }

  sort(arr + 1, arr + 1 + n, comp);

  for(int i = 1; i <= n; i++){
     int l = arr[i].l, r = arr[i].r, idx = arr[i].idx;
     ans[idx] = query(1, 1, MAXN, l + 1, MAXN);
     update(1, 1, MAXN, l);
  }

  for(int i = 1; i <= n; i++){ 
     cout << ans[i] << endl;
  }

  return 0;
}
