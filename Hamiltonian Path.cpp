// given a graph, check if there exist hamiltonian path in it.
// More on hamiltonian path : https://en.wikipedia.org/wiki/Hamiltonian_path
// Source : https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/

bool checkHamiltonianPath(int adj[][MAXN], int n)
{
    bool dp[MAXN][1 << MAXN];
    memset(dp, false, sizeof(dp));

    for(int i = 0; i < n; i++)
        dp[i][1 << i] = true;

    for(int i = 0; i < (1 << n); i++)
    {
        for(int j = 0; j < n; j++)
        {
        	if(i & (1 << j))
        	{
              for(int k = 0; k < n; k++)
              {
                  if(i & (1 << k) && adj[k][j] && k != j && dp[k][i ^ (1 << j)])
                  {
                    dp[j][i]=true;
                    break;
                  }
              }
          }
        }
    }

    for(int i=0; i<n; i++)
    {
      if(dp[i][(1 << n)-1])
        return true;
    }

    return false;
}

// time complexity : O(2^n.n^2)
