
problem1: https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/
int countDistinctSubstrings(string s) { // O(n^2), n = string size
        int n = s.size();
        const int p = 31;
        const int m = 1e9 + 7;
        vector<long> p_pow(n);

        p_pow[0] = 1;
        vector<long> hash(n + 1, 0);

        for (int i = 0; i < n; i++){
            if(i > 0)
              p_pow[i] = (p_pow[i-1] * p) % m;
            hash[i+1] = (hash[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
        }
        int unique_substrings = 0;
        unordered_set<int> hash_set;
        
        for (int len = 1; len <= n; len++) {
            hash_set.clear();
            for (int i = 0; i <= n - len; i++) { 
                long cur_h = (hash[i + len] + m - hash[i]) % m;
                cur_h = (cur_h * p_pow[n - i - 1]) % m;
                hash_set.insert((int)cur_h);
            }
            unique_substrings += hash_set.size();
        }
        
        return unique_substrings;
    }
};


// problem 2 : https://codeforces.com/contest/514/problem/C [changing a char of string and looking for it in dictonary]
// solution 2 : https://codeforces.com/contest/514/submission/61571617
// problem 3 : //problem : https://codeforces.com/contest/271/problem/D 
