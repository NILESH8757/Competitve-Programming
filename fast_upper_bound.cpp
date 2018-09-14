//source: https://academy.realm.io/posts/how-we-beat-cpp-stl-binary-search/
// if no element is greater than value, returns size of container.
//24% faster self-written upper bound than c++ stl's upper_bound()
#include<bits/stdc++.h>
using namespace std;

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

int main()
{
  int n,value;
  cin>>n>>value;
  vector<int> a(n);
  for(int i=0;i<n;i++)
   cin>>a[i];
  
  sort(a.begin(),a.end());
  int pos=fast_upper_bound(a,value);
  
  cout<<pos;
}

/*
input:
5 6
3 5 7 8 12

output:
2
*/
