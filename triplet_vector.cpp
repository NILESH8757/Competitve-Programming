/*
I have several integer elements like this:
(3 9 1), (1 5 2), (2 8 3), (1 4 4), (1 6 5), (1 5 6).

After sorting it should look like this:
(1 4 4), (1 5 2), (1 5 6), (1 6 5), (2 8 3), (3 9 1).
*/

// code-

vector<array<int,3>> vec;
int n,x,y,z;
cin>>n;
while(n--)
{
    cin>>x>>y>>z;
    vec.push_back({x,y,z});
}

sort(vec.begin(), vec.end());

for(auto v: vec)
{
    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
}
