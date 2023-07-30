// Problem1: https://leetcode.com/problems/count-stepping-numbers-in-range
// Problem1's solution(observe how cleverly 0 is handled with 10 as 'last' flag):
class Solution {
public:

  int dp[102][2][12], n;
  string s;
  const int mod = 1e9 + 7;
    
    int countSteppingNumbers(int idx, int tight, int last){
        if(idx == n) {
           return 1;
        }
        int &ans = dp[idx][tight][last];
        if(ans != -1)
            return ans;

        ans = 0;
        int current_digit = (s[idx] - '0');
        int higher_digit = last + 1;
        int lower_digit = last - 1;

        int limit = tight ? current_digit : 9;
        
        if(last == 10){
            for(int i = 0; i <= limit; i++){
               ans += countSteppingNumbers(idx + 1, tight & (i == limit), i == 0 ? 10: i);
               ans %= mod;
            }
        } else{
           if(higher_digit <= limit){
              ans += countSteppingNumbers(idx + 1, tight & (higher_digit == limit), higher_digit);
              ans %= mod;
           }
           if(lower_digit >= 0 && lower_digit <= limit){
              ans += countSteppingNumbers(idx + 1, tight & (lower_digit == limit), lower_digit);
              ans %= mod;
           }
        }
        
        return ans;
    }
    int countSteppingNumbers(string low, string high) {
         s = high;
         n = s.size();
         memset(dp, -1, sizeof(dp));
         int ans = countSteppingNumbers(0, 1, 10); // 10 is flag for leading zero

         s = low;
         n = s.size();
         memset(dp, -1, sizeof(dp));
         ans = (ans - countSteppingNumbers(0, 1, 10) + mod) % mod;

         bool check_low = true;
         for(int i = 1; i < low.size(); i++){
             if(abs(low[i] - low[i - 1]) != 1)
                check_low = false;
         }
         if(check_low){
             ans++;
             ans %= mod;
         }
         return ans;
    }
};
//Problem2 (similar as problem1):  https://cses.fi/problemset/task/2220/ [solution: https://cses.fi/problemset/result/6643437/]
//Problem3 : https://atcoder.jp/contests/dp/tasks/dp_s 
//Problem4 : https://leetcode.com/problems/count-of-integers 
//Problem5: (digit dp with bitmask): https://leetcode.com/problems/count-special-integers
