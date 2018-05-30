
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int a[N],bit[N],n;

void update(int x,int del)
{
  for(;x<=n;x+=x&-x)
  {
    bit[x]+=del;
  }
}

int query(int x)
{
  int sum=0;
  for(;x>0;x-=x&-x)
  {
    sum+=bit[x];
  }
  return sum;
}

int main()
{

  cin>>n;
  
  for(int i=1;i<=n;i++)
    cin>>a[i];

  int inv=0;
  for(int i=1;i<=n;i++)
  {
    inv+=query(n)-query(a[i]);
    update(a[i],1);
  }
  cout<<inv;

 return 0;
}
