//Dearrange given unsorted array so that, no element remains in their original place
//Blog: https://codeforces.com/blog/entry/66176
//Problem: https://www.codechef.com/problems/MARCAPS

int main()
{ 
 
  int t,n,x;
  cin>>t;

  while(t--)
  {
    cin>>n;
    
    int mx=0;
    map<int,int> mp;
    vector<int> res(n);
    vector<pair<int,int> > a;

    for(int i=0;i<n;i++)
    {
      cin>>x;
      a.push_back({x,i});
      mp[x]++;
      mx=max(mx,mp[x]);
    }
    
    if(2*mx>n)
    {
      cout<<"No"<<endl;
      continue;
    }

    sort(a.begin(), a.end());
    
    for(int i=0;i<a.size();i++)
    {
      int pos=(i+mx)%n;
      res[a[pos].second]=a[i].first;  
    }

    cout<<"Yes\n";
    for(int i=0;i<n;i++)
      cout<<res[i]<<' ';

    cout<<endl;
  }
/*
Also, no. of dearrangements of n distinct object is, 
   D(n) = (n − 1)(D(n − 1) + D(n − 2)).
*/
