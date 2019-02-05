//problem: https://www.spoj.com/problems/GSS1/

#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=500005;
const int inf=-1e10;
int n;
int a[N];

struct data
{
  int sum,pref,suff,ans;
};

data tree[4*N];

data combine(data l,data r)
{
  data res;
  res.sum=l.sum + r.sum;
  res.pref=max(l.pref,l.sum+r.pref);
  res.suff=max(r.suff,r.sum+l.suff);
  res.ans=max(max(l.ans,r.ans),l.suff+r.pref);

  return res;
}

data make_data(int val)
{
  data res;
  res.sum=res.pref=res.suff=res.ans=val;
  return res;
}

void build(int v,int tl,int tr)
{
  if(tl==tr)
    tree[v]=make_data(a[tl]);
  else
  {
    int tm=(tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    tree[v]=combine(tree[v*2],tree[v*2+1]);
  }
}

data query(int v, int tl, int tr,int l,int r)
{
  if (l>r)
    return make_data(inf);
  if(l==tl and r==tr)
    return tree[v];
  int tm=(tl+tr)/2;
  return combine(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(l,tm+1),r));
}

int32_t main() 
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
  #endif
  scanf("%lld",&n);

  for(int i=1;i<=n;i++)
    scanf("%lld",&a[i]);
  build(1,1,n);
  int m;
  scanf("%lld",&m);
  while(m--)
  {
    int x,y;
    scanf("%lld %lld",&x,&y);
    data res=query(1,1,n,x,y);
    printf("%lld\n",res.ans);
  }
  return 0;
}
