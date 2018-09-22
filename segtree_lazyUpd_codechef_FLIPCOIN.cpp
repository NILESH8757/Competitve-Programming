
#include<bits/stdc++.h>
using namespace std;

#define int long long


int tree[2000050], n, lazy[2000050];

void update(int node, int a, int b, int i, int j)
{
    if(lazy[node] & 1)
    {
        tree[node] = b-a+1 - tree[node];

        if(a != b)
        {
            lazy[2*node]++;
            lazy[2*node+1]++;
        }
        lazy[node] = 0;
    }

    if(a > j or b<i or a > b)
        return;

    if(a >= i and b <= j)
    {
        tree[node] = b-a+1 - tree[node];
        if(a != b)
        {
            lazy[2*node]++;
            lazy[2*node+1]++;
        }

        return;
    }

    int mid = (a + b) / 2;
    update(2*node, a, mid, i, j);
    update(2*node+1, mid+1, b, i, j);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int a, int b, int i, int j)
{
    if(a > j || b < i || a > b)
        return 0;

    if(lazy[node] & 1)
    {
        tree[node] = b-a+1 - tree[node];
        if(a != b)
        {
            lazy[2*node]++;
            lazy[2*node+1]++;
        }
        lazy[node] = 0;
    }
    if(a >= i && b <= j)
        return tree[node];

    int mid = (a + b)/2;
    int p1 = query(2*node, a, mid, i, j);
    int p2 = query(2*node+1, mid+1, b, i, j);
    return p1+p2;
}

int32_t main()
{
   
    int q,t, l, r;
    scanf("%lld %lld",&n,&q);

    while(q--)
    {
        scanf("%lld %lld %lld",&t,&l,&r);
        if(t == 0)
        {
            update(1, 1, n, l+1, r+1);
        }
        else
        {
            printf("%lld\n",query(1, 1, n, l+1, r+1));    
        }
    }

    return 0;
}

