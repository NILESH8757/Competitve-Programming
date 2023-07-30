// Problem1: https://leetcode.com/problems/count-stepping-numbers-in-range
// Problem1's solution:
class Solution {
public:
  int dp[102][2][12][2], n;
  string s;
  const int mod = 1e9 + 7;
  // not including 0 in answer as constraints > 0
  int countSteppingNumbers(int idx, int smaller, int last, int is_zero){
      if(idx == n) {
         return is_zero ? 0: 1;
      }
      int &ans = dp[idx][smaller][last][is_zero];
      if(ans != -1)
          return ans;

      int limit = 9;
      if(smaller)
          limit = s[idx] - '0';

      ans = 0;

      for(int i = 0; i <= limit; i++) {
          
          int next_smaller = smaller;
          if(smaller && i < limit)
            next_smaller = 0;
          int will_be_zero = is_zero;
          if(is_zero && i > 0)
            will_be_zero = 0;

          if(is_zero){
              ans += countSteppingNumbers(idx + 1, next_smaller, i, will_be_zero);
              ans %= mod;
          } else{
              if(abs(i - last) == 1){
                ans += countSteppingNumbers(idx + 1, next_smaller, i, will_be_zero);
                ans %= mod;
              }
          }
      }
      return ans;
  }
  int countSteppingNumbers(string low, string high) {
       s = high;
       n = s.size();
       memset(dp, -1, sizeof(dp));
       int ans = countSteppingNumbers(0, 1, 0, 1);

       s = low;
       n = s.size();
       memset(dp, -1, sizeof(dp));
       ans = (ans - countSteppingNumbers(0, 1, 0, 1) + mod) % mod;

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
//Problem2 (same as problem1) includes 0 (but in adhoc manner):  https://cses.fi/problemset/task/2220/
//Problem3 (without use of zero flag): https://atcoder.jp/contests/dp/tasks/dp_s 
//Problem4 (without use of zero flag): https://leetcode.com/problems/count-of-integers 
//Problem5: (digit dp with bitmask): https://leetcode.com/problems/count-special-integers
