// nth catalan number modulo M (prime) in O(n).
// formula : nth catalan num = (2n C n) / (n + 1) = (2n!) / ( (n + 1)! * n! )

int modexp(int base, int exp,int M)
{
    int res = 1;
    while(exp) 
    {
       if(exp & 1) 
           res = (1LL * res * base) % M;
       base = (1LL * base * base) % M;
       exp /= 2;
    }
    return res % M;
}

int nthCatalan(int n) 
{
    const int mod = 1e9 + 7;
    int x = 1LL, a = 1, b = 1, c = 1;

    for(int i = 1; i <= 2 * n; i++)
    {
        x = (1LL * x * i) % mod;
        if(i == 2 * n)
         a = x;
        if(i == n + 1)
         b = x;
        if(i == n)
         c = x;
    }
    
    b = modexp(b, mod - 2, mod);
    c = modexp(c, mod - 2, mod);
    a = (1LL * a * b) % mod;
    a = (1LL * a * c) % mod;
    
    return (int)a;
}
