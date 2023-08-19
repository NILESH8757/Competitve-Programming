// Problem1: https://leetcode.com/problems/number-of-beautiful-integers-in-the-range
class Solution {
public:
    int dp[11][2][11][11][21][2];
    string s;
    int n, k;
    int countBeautifulNumbers(int idx, int tight, int evens, int odds, int rem, int zero){
    
        if(idx >= s.size()) {
           return (odds == evens) && (rem == 0) && (zero == 0);
        }

        int &ans = dp[idx][tight][evens][odds][rem][zero];
        if(ans != -1)
            return ans;

        int limit = tight ? (s[idx] - '0') : 9;
        
        ans = 0;
        
        for(int i = 0; i <= limit; i++){
            int new_tight = tight & (i == limit);
            int new_zero = zero ? i == 0 : 0;
            int new_evens = evens;
            int new_odds = odds;
            int new_rem = ((rem * 10) + i) % k;
            if(new_zero == 0){
                new_evens = evens + (i % 2 == 0);
                new_odds = odds + (i & 1);
            }
            ans += countBeautifulNumbers(idx + 1, new_tight, 
                    new_evens, new_odds, new_rem, new_zero);
        }
        return ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        this->k = k;
        memset(dp, -1, sizeof(dp));
        s = to_string(high);
        n = s.size();
        int high_ans = countBeautifulNumbers(0, 1, 0, 0, 0, 1);
        memset(dp, -1, sizeof(dp));
        s = to_string(low - 1);
        n = s.size();
        int low_ans = countBeautifulNumbers(0, 1, 0, 0, 0, 1);
        int ans = high_ans - low_ans;
        return ans;
    }
};
//Problem2 :  https://cses.fi/problemset/task/2220/ [solution: https://cses.fi/problemset/result/6643437/]
//Problem3 : https://atcoder.jp/contests/dp/tasks/dp_s 
//Problem4 : https://leetcode.com/problems/count-of-integers 
//Problem5: (digit dp with bitmask): https://leetcode.com/problems/count-special-integers
