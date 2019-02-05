//problem: spoj's HORRIBLE
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
#define int long long 

int arr[MAXN],tree[MAXN<<2],lazy[MAXN<<2];

void build(int node,int a,int b)
{
	if(a==b)
	{
		tree[node]=arr[a];
		return;
	}
	int mid=(a+b)>>1;
	build(2*node,a,mid);
	build(2*node+1,mid+1,b);

	tree[node]=tree[2*node] + tree[2*node + 1];
} 

void rangeUpdate(int node,int a,int b,int i,int j,int val)
{
	if(lazy[node]!=0)
	{
		tree[node] += (b-a+1)*lazy[node];

		if(a!=b)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node + 1] += lazy[node];
		}

		lazy[node] = 0;
	}

	if(a > b or a > j or b < i) // out of range
		return ;

	if(a >= i and b <= j)
	{
		tree[node] += (b-a+1)*val;

		if(a!=b)
		{
			lazy[2*node] += val;// earlier lazy[node];
			lazy[2*node + 1] += val;//earlier lazy[node];
		}
		return ;
	}

	int mid = (a+b) >> 1;

	rangeUpdate(2*node,a,mid,i,j,val);
	rangeUpdate(2*node+1,mid+1,b,i,j,val);

	tree[node] = tree[2*node] + tree[2*node + 1];
}

int query(int node,int a,int b,int i,int j)
{
	if(a > b or a > j or b < i)
		return 0;

	if(lazy[node]!=0)
	{
		tree[node] += (b-a+1)*lazy[node];

		if(a!=b)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node + 1] += lazy[node];
		}

	    lazy[node]=0;
	}

	if(a >= i and b <= j)
		return tree[node];

	int mid= (a+b) >> 1;

	int q1 = query(2*node,a,mid,i,j);
	int q2 = query(2*node + 1, mid+1,b,i,j);

	return q1+q2;
}
int32_t main()
{
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
   #endif	
   int n,q,t;
   scanf("%lld",&t);
   for(int tc=0;tc<t;tc++){
   memset(arr,0,sizeof(arr));
   memset(tree,0,sizeof(tree));
   memset(lazy,0,sizeof(lazy));

   scanf("%lld %lld",&n,&q);

   //build(1,1,n);
   
   int type,l,r,val;

   while(q--)
   {
     scanf("%lld",&type);
     if(type==0) // 0 l r val : add arr[l...r] to val
     {
     	scanf("%lld %lld %lld",&l,&r,&val);
     	rangeUpdate(1,1,n,l,r,val);
     }
     else //1 l r : find sum of arr[l...r]
     {
       scanf("%lld %lld",&l,&r);
       printf("%lld\n",query(1,1,n,l,r));
     }
   }
 }
  return 0;
}
