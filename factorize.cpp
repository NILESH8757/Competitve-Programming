//get all prime factors wiht exponents

map<int,int> factorize(int n)
{
  int cnt=0;
  map<int,int> mp;
  while(!(n%2))
  {
    n>>=1;
    cnt++;
  }
  if(cnt)
   mp[2]=cnt;

  for(int i=3;i*i<=n;i+=2)
  {
    cnt=0;
    while(!(n%i))
    {
      n/=i;
      cnt++;
    }
    if(cnt)
     mp[i]=cnt;
  }
  if(n>2) //left no. is prime
    mp[n]=1;

  return mp;
}

// sieve method to get all count of all prime factors in all integers 1 to N
//problem : https://codeforces.com/contest/546/problem/D

const int N = 5e6 + 10;
int pf[N], pdiv[N], pfsum[N];

//pf[i] = total count of prime factors of i, eg. pf[24] = 24, because 24 = 2 * 2 * 3 * 3
// pdiv[i] = least prime divisor of i, for eg. pdiv[10] = 2, pdiv[7] = 7
void sieve()
{
   for(int i = 2; i < N; i++)
   {
      if(pdiv[i] == 0)
      {
         for(int j = i; j < N; j += i)
         {
            pdiv[j] = i;
         }
      }
   }

   for(int i = 2; i < N; i++)
   {
     pf[i] = 1 + pf[i / pdiv[i]];
   }
} 

int main()
{ 
  sieve();
  for(int i = 1; i < N; i++)
    pfsum[i] = pfsum[i - 1] + pf[i];
  
  int t, a, b;

  scanf("%d", &t);

  while(t--)
  {
     scanf("%d %d", &a, &b);
     printf("%d\n", pfsum[a] - pfsum[b]);
  }  
  
  return 0;
}
