//connected components in graph
#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
vector<int> adj[N];
int component[N];
bool vis[N];
int n,comp=0;
void dfs(int i)
{
    vis[i]=true;
    component[i]=comp;
    for(int j: adj[i])
    {
      if(!vis[j])      
       dfs(j);
    }
}
 
int main()
{
    int e,x,y,i;
    memset(vis,false,sizeof(vis));
    cin>>n; //no. of nodes
    cin>>e; // no. of edges
    for(i=0;i<e;i++)
    {
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            comp++;
            dfs(i);
        }
    }
  /* for(i=1;i<=n;i++)
     {
         cout<<i<<" belongs to component "<<component[i]<<endl;
     } */
   vector<int> c[comp+2];
    for(i=1;i<=n;i++)
    {
       c[component[i]].push_back(i);
    }
    for(i=1;i<=comp;i++)
    {
      cout<<"\nnodes in component "<<i<<":\n";
      for(int j: c[i])
        cout<<j<<" ";
    }
 
 return 0;
}
