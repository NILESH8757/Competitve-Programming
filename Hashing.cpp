//problem : https://codeforces.com/contest/271/problem/D

#include<bits/stdc++.h>
 using namespace std;
#define int long long

string bad,str;
int k;

//first problem using rolling hash :)

int count_unique_good_substrings(string const& s) 
{
  //source:https://cp-algorithms.com/string/string-hashing.html

    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<int> p_pow(n),good(n+1, 0);

    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    for(int i = 0; i < n; i++)
    {
      if(bad[s[i] - 'a'] == '0')
        good[i + 1]++;
    
      good[i + 1] += good[i];
    }
    

    vector<int> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    set<int> hs;
    
    for (int l = 1; l <= n; l++) 
    {
        hs.clear();
       
        for (int i = 0; i <= n - l; i++) 
        { 
            if(good[i + l] - good[i] > k) continue;

            int cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        
        cnt += hs.size();
    }
    
    return cnt;
}

int32_t main()
{ 
  
 cin >> str >> bad >> k;

 cout<<count_unique_good_substrings(str);

 return 0;
}
