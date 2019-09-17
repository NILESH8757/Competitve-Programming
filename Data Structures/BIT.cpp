// Nice blog : https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/

const int N = 1e5 + 5;
int BIT[N], n;

void update(int idx, int val)
{
	while(idx <= n)
	{
		BIT[idx] += val;
		idx += idx & (-idx);
	}
}

int query(int idx)
{
  int ans = 0;
  while(idx)
  {
  	ans += BIT[idx];
  	idx -= idx & (-idx);
  }
  return ans;
}

int main()
{ 
	
  int l, r, q;
  cin >> n >> q;
  // range update + point query
  while(q--)
  {
	int type, pos;
	cin >> type;
	  
	if(type == 1)
	{
	    cin >> l >> r; // increment A[l...r] by 1
	    update(l, 1);
	    update(r + 1, -1);
	}
	else
	{
	    cin >> pos; // get A[pos]	
	    cout << query(pos) << endl;
	}
  }
	

  return 0;
}
// (range Update + range query) problem: https://codeforces.com/contest/283/problem/A
// solution : https://codeforces.com/contest/283/submission/60725008
