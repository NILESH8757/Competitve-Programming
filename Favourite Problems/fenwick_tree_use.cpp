//https://codeforces.com/problemset/submission/799/91078039

// what a nice use of fenwick tree :)
#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
int bit[2][N];

void update(int i, int idx, int val){
    for(; idx < N; idx += (idx & -idx)){
        bit[i][idx] = max(bit[i][idx], val);
    }
}

int query(int i, int idx){
    int ans = 0;
    for(; idx; idx -= (idx & -idx))
        ans = max(ans, bit[i][idx]);
    return ans;
}

int main(){
    int n, c, d;
    cin >> n >> c >> d;
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        int b, p;
        char type;
        
        cin >> b >> p >> type;
        
        if(type == 'C' && p <= c){
            int other = max(query(0, c - p), query(1, d));
            if(other)
                ans = max(ans, b + other);
            
            update(0, p, b);
        }
        
        if(type == 'D' && p <= d){
            int other = max(query(1, d - p), query(0, c));
            if(other)
                ans = max(ans, b + other);
            
            update(1, p, b);
        }
    }
    
    cout << ans << endl;
    return 0;
}
