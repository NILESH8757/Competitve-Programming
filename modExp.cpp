//HackerRank Problem: Tower 3-coloring

#include<bits/stdc++.h>
using namespace std;

// recursive

long long modPower(long long base, long long power, long long mod) {
    if (power == 0)
        return 1;
    long long res = modPower(base, power / 2);
    res = (res * res) % mod;
    if(power & 1LL) 
        res = (res * base) % mod;
    return res;
}

// iterative

int modexp(int base, int exp,int M) {
    //(base ^ exp ) % M
    int res = 1LL;
    while(exp) {
       if(exp & 1) 
           res = (res * base) % M;
       base = (base * base) % M;
       exp /= 2;
    }
    return res % M;
}

//modular inverse
int modInverse(int a, int m) { 
 // (a ^ -1) % m, m must be prime
 return modexp(a, m-2, m);   
} 

int main() {
    int n, tem, ans;
    cin >> n;
    const int MOD = 1e9 + 7;
    tem = fast_exp(3, n, MOD - 1);
    ans = fast_exp(3, tem, MOD);
    cout << ans;
    return 0;
}
