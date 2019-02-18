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
