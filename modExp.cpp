//HackerRank Problem: Tower 3-coloring

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;

ll fast_exp(ll base, ll exp,ll M) 
{
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%M;
       base=(base*base)%M;
       exp/=2;
    }
    return res%M;
}

int main() 
{
    ll n,tem,ans;
    cin>>n;
    tem=fast_exp(3,n,MOD-1);
    ans=fast_exp(3,tem,MOD);
    cout<<ans;
    return 0;
}
