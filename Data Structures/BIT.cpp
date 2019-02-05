
#include<bits/stdc++.h>
 using namespace std;
 
#define FIO                     ios_base::sync_with_stdio(false); cin.tie(0)
#define mod                     1000000007
#define setbits                 __builtin_popcount
#define gcd                     __gcd
#define rep(i,a,b)              for(int i=a;i<=b;i++)
#define repr(i,b,a)             for(int i=b;i>=a;i--)
#define foreach(itr, c)         for( __typeof__( (c).begin()) itr = (c).begin();  itr != (c).end(); ++itr)
#define all(a)                  a.begin(), a.end()
#define in(a,b)                 ( (b).find(a) != (b).end())
#define pb                      push_back
#define fill(a,v)               memset(a, v, sizeof a)
#define endl                    "\n"
#define ff                      first
#define ss                      second
#define mp                      make_pair
#define minin(a)                *min_element (all(a))
#define maxin(a)                *max_element(all(a))
#define asort(c)                sort(all(c))
#define dsort(c)                sort(all(c), greater<int>())
typedef  long long                   ll;
typedef  vector<int>                 vi;
typedef  pair<int, int>              ii;
typedef  vector<ii>                 vii;
typedef  set<int>                    si;
typedef  unordered_map<string,int>  msi;
typedef  long double                 ld;

const int N=1e5+5;

int BIT[N],n;
void update(int idx,int val)
{
	while(idx<=n)
	{
		BIT[idx]+=val;
		idx+=idx&(-idx);
	}
}

int query(int idx)
{
  int ans=0;
  while(idx)
  {
  	ans+=BIT[idx];
  	idx-=idx&(-idx);
  }
  return ans;
}

int main()
{
  FIO;
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
  #endif
  int l,r,q;
  cin>>n>>q;
  while(q--)
  {
  	cin>>l>>r;
  	update(l,1);
  	update(r+1,-1);
  }
  int idxFrequency[n+1];
  rep(i,1,n)
  {
  	idxFrequency[i]=query(i);
  }

  rep(i,1,n)
  cout<<idxFrequency[i]<<" ";

 return 0;
}
