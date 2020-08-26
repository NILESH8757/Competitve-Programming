// problem : https://codeforces.com/contest/888/problem/E
// solution : https://codeforces.com/contest/888/submission/91059795


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    set<int> First, Second;
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans = max(ans, a[i] % m);
    }
    
    int half = n / 2;
    int otherHalf = n - half;
    
    for(int i = 0; i < (1 << half); i++){
        int cur = 0;
        for(int j = 0; j < half; j++){
            if(i & (1 << j)){
                cur += a[j];
                cur %= m;
            }
        }
        First.insert(cur);
    }
    
    for(int i = 0; i < (1 << otherHalf); i++){
        int cur = 0;
        for(int j = 0; j < otherHalf; j++){
            if(i & (1 << j)){
                cur += a[half + j];
                cur %= m;
            }
        }
        Second.insert(cur);
    }
    
    for(int i : First){
        int x = m - i;
        auto j = Second.lower_bound(x);
        if(j == Second.end())
            --j;
        ans = max(ans, (i + *j) % m);
        
        if(j != Second.begin()){
            --j;
             ans = max(ans, (i + *j) % m);
        }
    }
    
    cout << ans;
    return 0;
}
