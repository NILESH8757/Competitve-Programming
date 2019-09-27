//This problem was asked in byjus developer hiring challenge on HackerEarth on 14th sept,2018
/* Problem Statement:
There are N stall in a vegetable market that are selling vegetables. You've to buy an equal amount of vegetables from each
stall. If a stall does not have enough vegetables to offer, then you have to buy all the vegetables
available in that stall.If you are given the number of vegetables that every stall can offer, determine the minimum quantity 
that you need to buy from each stall such that you  have at least K vegetables in total.

input:
N
A1,A2,A3,.....,AN
Q(no. of queries)
next Q lines each K
output:
for each query print answer on new line. If not possilbe for given K, print -1.

constraint:
1<=N<=100000
1<=Ai<=1000000
1<=Q<=100000
1<=Ki<=10^11

*/

#include<bits/stdc++.h>
 using namespace std;
#define int  long long
#define vi  vector<int>
#define rep(i,n)  for(int i=0;i<n;i++)
#define all(c)  c.begin(),c.end()
#define asort(c)  sort(all(c))
 
 
template <class T> inline size_t fast_upper_bound(const vector<T>& vec, T value)
{
    size_t m_len = vec.size();
    size_t low = -1;
    size_t high = m_len;
    assert(m_len < std::numeric_limits<size_t>::max() / 2);
    while (high - low > 1) 
    {
        size_t probe = (low + high) / 2;
        T v = vec[probe];
        if (v > value)
            high = probe;
        else
            low = probe;
    }
 
    if (high == m_len)
        return m_len;
    else
        return high;
}
 
//code:

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
 
 
 
  int len,position,maxelement=0,total=0,sum,k;
 
  cin>>len;
  vi pre(len),arr(len);
 
  rep(i,len)
  {
    cin>>arr[i];
    total+=arr[i]; 
    maxelement=max(maxelement,arr[i]);
  }
 
  asort(arr);
 
  rep(i,len)
   pre[i]=(i==0)?arr[i]:arr[i]+pre[i-1];
 
  int queries;
  cin>>queries;
 
  rep(i,queries)
  {
 
    cin>>k;
    if(k>total)
      cout<<"-1"<<endl;
    else if(k<=len)
      cout<<1<<endl;
    else if(len==1)
      cout<<k<<endl;
    else
    {
        int left=1,right=maxelement,mid;
 
        int times=22;
        rep(run,times)
        {
          mid=(left+right)/2;
          position=fast_upper_bound(arr,mid);
          if(position==0)
           sum=mid*len;
          else if(position==len and maxelement==mid)
            sum=total;
          else
            sum=pre[position-1]+(len-position)*mid;
 
          if(sum>=k)
            right=mid;
          else
            left=mid;
        }
       cout<<right<<endl;
   }
  }
 
  return 0;
}  

/* sample test case:
input:
5
3 8 4 1 7
5
13
19
3
25
22

output:
3
6
1
-1
7

*/
