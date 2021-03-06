//Given N intervals and Q points . For each points find, in how many intervals it lies.
// for ex- point 5 lies in three intervals out of given five intervals: [2,7] , [5,5] , [3,9] , [11,16] and [15,33]
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <utility>
 
std::vector<std::pair<int,std::pair<int,int>> > st;

void sweep(int n , int q )
{
     std::vector<int>ans(q,0);
     sort(st.begin(),st.end());
     
     int sum=0,nn=st.size();
 
     for(int i = 0 ; i < nn ; i++ )
     {
         int xx = st[i].first ;
         int type = st[i].second.first ;
         int id = st[i].second.second ;
         if(type == -1)
         {
            sum++;
         }
         else if(type == 1 )
         {
            sum--;
         }
         else 
         {
             ans[id]=sum;
         }
     }
     for(int i = 0 ; i < q ; i++ )
     {
        printf("%d\n", ans[i]);
     }
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
     int n , q ;

     scanf("%d %d",&n,&q);
     
     int x , y ;

     for(int i = 0 ; i < n ; i++ )
     {
         scanf("%d %d",&x,&y) ;
         st.push_back({x,{-1,i}}) ;
         st.push_back({y,{1,i}});
     }

     for(int i = 0 ; i < q ; i++ )
     {
        scanf("%d",&x);
        st.push_back({x,{0, i}});
     }

     sweep(n,q);

     return 0 ;
 }
//-----------------------------------------Another variation of line sweep algorithm-------------------
/*
  Given N intervals and a value k, remove minimal no. of intervals such that no points has cover of more than k intervals
*/
// problem : https://codeforces.com/contest/1249/problem/D2
// solution : https://codeforces.com/contest/1249/submission/63202336
