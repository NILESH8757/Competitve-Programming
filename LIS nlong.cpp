// Longest Increasing Subsequence

int LIS(vector<int>& nums) 
{
    vector<int> res; // this array shall not contain any valid LIS at the end, but it's sizse will denote lenght of lis
    
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
