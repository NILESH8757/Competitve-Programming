/* this was asked in HE problemsetter hiring contest, in sept., 2019.

   Problem : Given two arrays A and B, both of size N, count pairs of indices
             (i, j) such that gcd(A[i], B[j]) != 1.

   constraints : 1 <= N <= 10^5
                1 <= A[i], B[i] <= 10^6
*/

// Prerequisite : sieve + PIE
// idea : https://codeforces.com/blog/entry/55822?#comment-395305
// PIE : https://www.geeksforgeeks.org/inclusion-exclusion-principle-and-programming-applications/

#include<bits/stdc++.h>
 using namespace std;

#define  int  long long
const int N = 1e5 + 5;
const int MAXE = 1e6 + 5;

int A[N], B[N], n, cnt[MAXE]; //cnt[x]: in how many elements of array A did x appear as a factor
vector<int> pf[MAXE]; //pf[x] : prime factors of x without multiplicity

void sieve()
{
   for(int i = 0; i < MAXE; i++)
     pf[i].clear();

   for(int i = 2; i < MAXE; i++)
   {
      if(pf[i].empty())
      {
         int j = i; 
         while(j < MAXE)
         {
            pf[j].push_back(i);
            j += i;
         }
      }
   }
   
   int subx, sz, x;

   for(int i = 1; i <= n; i++)
   {
      x = A[i];

      if(x == 1) 
        continue;

      int sz = pf[x].size();

      for(int j = 1; j < (1 << sz); j++)
      {
          subx = 1;
          for(int k = 0; k < sz; k++)
          {
             if((j >> k) & 1)
             {
                subx *= pf[x][k];
             }
          }
          cnt[subx]++;
      }
   }
}


int32_t main()
{ 
  
  cin >> n;

  for(int i = 1; i <= n; i++)
  {
    cin >> A[i];
  }

  sieve();

  for(int i = 1; i <= n; i++)
  {
    cin >> B[i];
  }

  int finalans = 0;
  
  for(int i = 1; i <= n; i++)
  {
     int x = B[i];
     if(x == 1)
      continue;

     
     int sz = pf[x].size(), odd = 0, even = 0;

     for(int j = 1; j < (1 << sz); j++)
     {
        int subx = 1;
        for(int k = 0; k < sz; k++)
        {
           if((j >> k) & 1)
           {
              subx *= pf[x][k];
           }
        }
        
        if(__builtin_popcountll(j) & 1)
          odd += cnt[subx];
        else
          even += cnt[subx];
     }
     
   
     finalans += (odd - even);
  }

  cout << finalans;

  return 0;
}
