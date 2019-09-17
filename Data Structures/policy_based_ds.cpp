// https://codeforces.com/blog/entry/11080
// https://codeforces.com/blog/entry/52460?#comment-439482

/*
  Problem: spoj's ORDERSET
  link: https://www.spoj.com/problems/ORDERSET/
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

 using namespace std;
 using namespace __gnu_pbds;


typedef tree< pair<int, int>, null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set s;
map<int,int> m;

int32_t main()
{ 
 
  int n,q,x;
  char op;
  
  cin>>q;
 
  while(q--)
  {
    cin>>op>>x;

    if(op=='D')
    {
      //cout<<"Delete "<<x<<endl;
      if(m[x])
       s.erase({x,--m[x]});

    }
    else if(op=='I')
    {
      //cout<<"insert "<<x<<endl;
      if(m[x]==0)
      s.insert({x,m[x]++});
    
    }
    else if(op=='K')
    {
      //cout<<"Find "<<x<<"th smallest"<<endl;
      if(s.size()<x)
      {
        cout<<"invalid\n";
        continue;
      }
      auto it=s.find_by_order(x-1);
      int ans=it->first;
      cout<<ans<<endl;
  
    }
    else //op=='C'
    {
     // cout<<"Count elements < "<<x<<endl;
      int ans= s.order_of_key({x, -1});
      cout<<ans<<endl;

    }
  }
  
 return 0;
}

// Problem 2 : https://www.codechef.com/MARCH19B/problems/SUBPRNJL
// Problem 3 : https://codeforces.com/problemset/problem/61/E [ solution: https://codeforces.com/contest/61/submission/59656466 ]
// Problem 4 (ordered_multiset) : https://codeforces.com/problemset/problem/459/D [ solution : https://codeforces.com/contest/459/submission/60728508
