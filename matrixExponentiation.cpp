//problem link: https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem
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
#define in(b,a)                 ( (b).find(a) != (b).end())// in container b,
#define pb                      push_back                  // check for element a
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
typedef  map<int, int>              mii;


struct mat
{
  ll m[2][2];
};

mat mul(mat a,mat b)//better to use standard matrix multiplication algorithm
{
  mat c; 
  c.m[0][0]=((a.m[0][0]*b.m[0][0])%mod + (a.m[0][1]*b.m[1][0])%mod ) % mod;
  c.m[0][1]=((a.m[0][0]*b.m[0][1])%mod + (a.m[0][1]*b.m[1][1])%mod ) % mod;
  c.m[1][0]=((a.m[1][0]*b.m[0][0])%mod + (a.m[1][1]*b.m[1][0])%mod ) % mod;
  c.m[1][1]=((a.m[1][0]*b.m[0][1])%mod + (a.m[1][1]*b.m[1][1])%mod ) % mod;
  
  return c;
}

mat matExp(mat mt,ll n)
{

  if(n==1)
    return mt;
  else
  {
    if(n%2==0)
    {
      mat temp=matExp(mt,n/2);
      return mul(temp,temp);
    }
    else
      return mul(mt,matExp(mt,n-1));
  }
}

int main()
{
  FIO;
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
  #endif

  int t;
  cin>>t;
  mat res,temp;
  ll ans;
  while(t--)
  {
    ll a,b,n;

   cin>>a>>b>>n;

   res.m[0][0]=1;
   res.m[0][1]=1;
   res.m[1][0]=1;
   res.m[1][1]=0;
   
   if(n==1)
   {
    cout<<b<<endl; 
     continue;
   }

   temp=matExp(res,n-1);

   ans=(((temp.m[0][0])*b)%mod + ((temp.m[0][1])*a)%mod)%mod;
  
   cout<<ans<<endl;

  }
  
 return 0;
}
