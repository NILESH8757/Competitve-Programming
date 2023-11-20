/*
  Point update: Assign value at an index,i.e. set A[idx]=value;
  Query: find range sum. For givne l,r find A[l]+A[l+1]+....+A[r]
*/
#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5; 
int n; 
int a[N], tree[2 * N];

// #define left(n) (2 * n)
// #define right(n) (2 * n + 1)

void build(int node, int start, int end) {
  if(start ==e nd) {
    tree[node] = a[start];
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

void update(int node, int start, int end, int idx, int val) {
  if(start == end) {
    a[idx] = val;
    tree[node] = val;
  } else {
    int mid = (start + end) / 2;
    if(start <= idx && idx <= mid){
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

int query(int node, int start, int end, int l, int r) {
  if(r < start || end < l) {
    return 0;
  }
  if(l <= start && end <= r) {
    return tree[node];
  }

  int mid = (start + end) / 2;
  int fromLeft = query(2 * node, start, mid, l, r);
  int fromRight = query(2 * node + 1, mid + 1, end, l, r);

  return(fromLeft + fromRight);
}



int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
   int n,q,l,r,idx,value,type;
   cin>>n>>q;
   for(int i=1;i<=n;i++)
     cin>>a[i];
   
   build(1,1,n);

   while(q--)
   {
    cin>>type;
    if(type==1)
    {
      cin>>idx>>value;
      update(1,1,n,idx,value);
      continue;
    }
    cin>>l>>r;
    cout<<query(1,1,n,l,r)<<endl;
   }
  return 0;
}
// Lazy propagation code for simple range sum update, range sum query : http://ideone.com/6o0Kml

// problem 1 : https://www.codechef.com/problems/FLIPCOIN   [ simple lazy propagation ]
// solution 1 : https://www.codechef.com/viewsolution/20283560

// problem 2 : https://www.spoj.com/problems/GSS1/ [ an interesting segtree problem ]
// solution 2 : http://ideone.com/0crQvB

// problem 3 : https://www.spoj.com/problems/HORRIBLE/ [ very easy lazy propagation for beginner ]
// solution 3 : http://ideone.com/F4Ugyi

// Problem 4 : https://codeforces.com/contest/242/problem/E [ Nice lazy progpagation]
// Solution 4 : https://codeforces.com/contest/242/submission/63120391

// Problem 5 : https://www.codechef.com/problems/MULTQ3  [Another nice lazy propagation]
