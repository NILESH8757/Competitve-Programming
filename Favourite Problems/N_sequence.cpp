/*
  using integers from 1 to K, generate N sequnces each of which is of length D such that no two sequence is identical.
  Print -1 if not possible.
  
  Problem: https://codeforces.com/problemset/problem/459/C
*/


#include <bits/stdc++.h>
 using namespace std;
const int MAX_N = 1015;
int res[MAX_N][MAX_N];

int possible(int people, int buses, int days)
{
    //Check if k^d > n
    for(int power = 1, d = 0; d <= days; power *= buses, d++)
    {
        if(power >= people)
            return true;
    }

    return false;
}

int main()
{
    int N, K, D;

    scanf("%d %d %d", &N, &K, &D);

    if(!possible(N, K, D))
    {
        printf("-1\n");
        return 0;
    }

    for(int p = 0; p < N; p++)
    {
        for(int d = 0; d < D; d++)
        {
            res[p][d] = (p == 0 ? 0 : res[p - 1][d]);
        }

        for(int d = D - 1; d >= 0; d--)
        {
            res[p][d]++;
            res[p][d] %= K;

            if(res[p][d])
                break;
        }

    }
    
    for(int d = 0; d < D; d++)
    {
        for(int p = 0; p < N; p++)
        {
            printf("%d ", res[p][d] + 1);
        }
        printf("\n");
    }

    return 0;
}
