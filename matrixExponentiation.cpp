//Taken from Ashishgup's repo
//https://github.com/Ashishgup1/Competitive-Coding/blob/master/Matrix%20Struct.cpp
//problem: https://codeforces.com/contest/1117/problem/D

#include<bits/stdc++.h>
 using namespace std;

const int MOD=1e9+7;
const int SZ = 105;
int n,m;

int add(int a, int b)
{
  int res = a + b;
  if(res >= MOD)
    return res - MOD;
  return res;
}

int mult(int a, int b)
{
  long long res = a;
  res *= b;
  if(res >= MOD)
    return res % MOD;
  return res;
}

struct matrix
{
  int arr[SZ][SZ];

  void makezeros()
  {
    memset(arr,0,sizeof(arr));
  }

  void reset() //set matrix according to problem
  {
    makezeros();
    arr[0][0] = 1;
    arr[0][m-1] = 1;

    for(int i = 1; i < m; i++)
      arr[i][i-1] = 1;
  }

  void makeiden()
  {
    makezeros();
    for(int i=0;i<m;i++)
    {
      arr[i][i] = 1;
    }
  }

  int res() //get result according to problem
  { 
    int ans = 0;
    for(int i = 0; i < m; i++)
     ans += arr[m-1][i];
    return ans%MOD;
  }

  matrix operator + (const matrix &o) const
  {
    matrix res;
    for(int i=0;i<SZ;i++)
    {
      for(int j=0;j<SZ;j++)
      {
        res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
      }
    }
    return res;
  }

  matrix operator * (const matrix &o) const
  {
    matrix res;
    for(int i=0;i<SZ;i++)
    {
      for(int j=0;j<SZ;j++)
      {
        res.arr[i][j] = 0;
        for(int k=0;k<SZ;k++)
        {
          res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
        }
      }
    }
    return res;
  }
};

matrix power(matrix a, int b)
{
  matrix res;
  res.makeiden();
  while(b)
  {
    if(b & 1)
    {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}

int32_t main() 
{
  cin >> n >> m;
  if(n < m)
  {
    cout << "1\n";
    return 0;
  }

  matrix mat;
  mat.reset();
  mat = power(mat,n);
  cout << mat.res() << endl;

  return 0;
}
