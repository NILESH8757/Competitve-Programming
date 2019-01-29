//Problem : https://www.spoj.com/problems/LVADER/
//Related Concept - Delannoy number(Combinatorics) : https://en.wikipedia.org/wiki/Delannoy_number

#include<bits/stdc++.h>
 using namespace std;

#define int long long
#define endl '\n'
const int N=1e5+5;
const int mod=1e9+7;

int F[N],inv[N],invF[N],P[N];

int ncr(int n,int k)
{
  int ret=(F[n]*invF[k])%mod;
  return (ret*invF[n-k])%mod;
}
int32_t main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  
  F[0]=F[1]=1;
  inv[1]=1;
  P[0]=1;
  P[1]=2;

  for(int i=2;i<N;++i)
  {
    inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
    F[i]=(F[i-1]*i)%mod;
    P[i]=(P[i-1]*2LL)%mod;
  }
  
  invF[0]=invF[1]=1;

  for(int i=2;i<N;i++)
    invF[i]=(invF[i-1]*inv[i])%mod;

  int x,y,m,n,t;

  cin>>t;
  int tc=1;
  while(t--)
  {
    cin>>x>>y>>m>>n;
    m-=x; n-=y;

    int ans=0;

    for(int k=0;k<=min(n,m);k++)
    {
      ans=(ans+((ncr(m,k)*ncr(n,k))%mod * P[k])%mod)%mod;
    }
    cout<<"Case "<<tc++<<": "<<ans<<endl;
  }
 return 0;
}
