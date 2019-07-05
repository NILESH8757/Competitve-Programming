#include<bits/stdc++.h>
 using namespace std;

/*
  Problem Statement: Given an unsorted array A of size n, find maximum 
                     gap between two adjacent elements in its sorted form in O(n).

  Editorial: https://leetcode.com/problems/maximum-gap/solution/
*/

int32_t main()
{ 
  
  int n, bucketSize, totalBuckets, largest = INT_MIN, smallest = INT_MAX;

  cin >> n;
  
  vector<int> A(n);
  
  for(int i = 0; i < n; i++)
  {
    cin >> A[i];
    largest = max(largest, A[i]);
    smallest = min(smallest, A[i]);
  }

  if(n < 2)
    return cout << -1, 0;

  bucketSize = (largest - smallest) / (n - 1);
  bucketSize = max(1, bucketSize);

  totalBuckets = (largest - smallest ) / bucketSize + 1;
 
  vector<pair<bool,pair<int,int > > > buckets(totalBuckets);

  for(auto &it: buckets)
  {
    it.first = false; // to check if bucket is used or not
    it.second.first = 1e9; //smallest element in a bucket
    it.second.second = -1e9; // largest element in a bucket
  }

  for(int i = 0; i < n; i++)
  {
    int val = A[i];
    int idx = (val - smallest) / bucketSize;
    buckets[idx].first = true;
    buckets[idx].second.first = min(buckets[idx].second.first, val);
    buckets[idx].second.second = max(buckets[idx].second.second, val);
  }

  int ans = 0, prevMax = smallest;

  for(auto b: buckets)
  {
    if(b.first == false) continue;

    ans = max(ans, b.second.first - prevMax);
    prevMax = b.second.second;
  }
  
  cout << ans;

 return 0;
}
