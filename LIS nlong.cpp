// Longest (strictly) Increasing Subsequence

int LIS(vector<int>& nums) 
{
    vector<int> res; // it doesn't store LIS. Stores just the length of LIS at the end of algorithm
    
    for(int i = 0; i < nums.size(); i++) 
    {
        auto it = lower_bound(res.begin(), res.end(), nums[i]); // use upper_bound for Longest non-decreasing subsequence
        if(it == res.end()) 
          res.push_back(nums[i]);
        else 
          *it = nums[i];
    }
    
    return res.size(); // return length of LIS
}
