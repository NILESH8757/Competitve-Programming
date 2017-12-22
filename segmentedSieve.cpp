#include <bits/stdc++.h>
using namespace std;
typedef long ll;
vector<ll> allPrimesupToN;
ll n;
const int N=5e6+5;
ll prm[N];
void simpleSieve(ll limit, vector<ll> &prime)
{
    
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));
 
    for (ll p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (ll i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }
 
    for (ll p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            //cout << p << "  ";
            allPrimesupToN.push_back(p);
        }
    }
}
 
void segmentedSieve(ll n)
{

    ll limit = floor(sqrt(n))+1;
    vector<ll> prime;  
    simpleSieve(limit, prime); 
    
    ll low  = limit;
    int high = 2*limit;
 
    while (low < n)
    {
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        for (ll i = 0; i < prime.size(); i++)
        {
          
            ll loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            for (ll j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        
        for (ll i = low; i<high; i++)
            if (mark[i - low] == true)
              allPrimesupToN.push_back(i);//cout << i << "  ";
 
        
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
}
 

int main()
{
	int t;
	cin>>t;
	n=90000000;
	segmentedSieve(n);
	for(ll i=0;i<allPrimesupToN.size();i++)
	{
		prm[i+1]=allPrimesupToN[i];
	}
	while(t--)
	{
      ll k; cin>>k;
      cout<<prm[k]<<endl;
	}
    return 0;
}
