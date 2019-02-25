// Euler's totient functino (phi[n]) as well as Pillai's arithmetical function ( F[n] )
/* 

Pillai's arithmetical function:  https://en.wikipedia.org/wiki/Pillai%27s_arithmetical_function
Problem: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/akash-and-gcd-1-15/description/

*/

const int MAXE=1e5+5;
int phi[MAXE],F[MAXE];

void compute()
{
    int i, j, k, ans;
    for(i = 0;i < MAXE;++i)
        phi[i] = i;
      
    for(i = 2;i < MAXE;++i)
    {
        if(phi[i] == i)
        {
            phi[i] = i - 1;
            for(j = 2*i;j < MAXE;j += i)
                phi[j] -= (phi[j] / i);
        }
    }
    for(i = 1;i < MAXE;++i)
    {
        for(j = i, k = 1;j < MAXE;j += i, k++)
        {
            F[j] += i*phi[k];
        }
    }
}
