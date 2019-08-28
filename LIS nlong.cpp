// Longest Increasing Subsequence

int LIS(vector<int>& nums) 
{
    vector<int> res; // at the end, it shall have any longest increasing subsequence
    
    for(int i = 0; i < nums.size(); i++) 
    {
        auto it = lower_bound(res.begin(), res.end(), nums[i]);
        if(it == res.end()) 
          res.push_back(nums[i]);
        else 
          *it = nums[i];
    }
    
    return res.size(); // return length of LIS
}
