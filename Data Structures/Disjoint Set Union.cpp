//motivation problem: https://www.codechef.com/problems/DISHOWN

const int N=1e4+5;
int par[N],rnk[N],n,connected,s[N],best[N];

void init()
{
  for(int v=1;v<=n;v++)
  {
    par[v]=v;
    rnk[v]=0;
  }
  connected=n;
}

int find_set(int v)//find() operation with path-compression optimization
{
  if(v==par[v])
    return v;
  return par[v]=find_set(par[v]);
}

void merge_set(int a,int b)  //union by rank
{
  a=find_set(a);
  b=find_set(b);
  if(a==b) 
    return;

  if(rnk[a]>rnk[b])
   par[b]=a;
  else
   par[a]=b;
  
  connected--;

  if(rnk[a]==rnk[b])
    rnk[a]++;
}

// another problem : https://cses.fi/problemset/result/1045648/
// soln. : https://cses.fi/paste/808deed8cf7122c8ff490/
