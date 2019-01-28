//problem link: https://codeforces.com/problemset/problem/264/B
//explanation: https://qr.ae/TUvNnv (by spj_29)
#include <bits/stdc++.h>
 using namespace std;

vector<int> factors[100001];
int a[100001],dp[100001],n;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    for(int i = 2; i <= 100000; i++)
    {
      if(factors[i].size() == 0)
        {
            for(int j = i; j <= 100000; j += i)
                factors[j].push_back(i);
        }
    }
    
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    int ans=0;
    
    for(int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for(int f: factors[a[i]])
            tmp = max(tmp, dp[f]);

        tmp++;
        ans = max(ans, tmp);

        for(int f: factors[a[i]])
            dp[f] = max(dp[f], tmp);
    }   

    cout<<ans;

  return 0;
}
