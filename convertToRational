//Author: Nightshade
//https://stackoverflow.com/questions/95727/how-to-convert-floats-to-human-readable-fractions 
#include<bits/stdc++.h>
using namespace std;
 
#define mod  1000000007
#define gcd  __gcd
typedef  long long  ll;
const long maxd=1e9+6; //maximum denominator
ll p,q;
void help(double x)   //taken from stackoverflow(visit link above)
{                
    ll am[2][2],it;   
    double  stx;
    stx=x;
    am[0][0]=am[1][1]=1;
    am[0][1]=am[1][0]=0;
    while(am[1][0]*(it=(ll)x)+am[1][1]<=maxd)
    {
        ll t;
        t=am[0][0]*it+am[0][1];
        am[0][1]=am[0][0];
        am[0][0]=t;
        t=am[1][0]*it+am[1][1];
        am[1][1]=am[1][0];
        am[1][0]=t;
        if(x==(double)it)
          break;     
        x=1/(x-(double)it);
        if(x>(double)0x7FFFFFFF)
          break; 
    } 
    p=am[0][0];
    q=am[1][0];
}
int main()
{
   double x;
   cin>>x;
   help(x);
   cout<<p<<"/"<<q<<endl;
   
 return 0;
}
