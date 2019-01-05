//taking n sentences,each on a newline..
//Problem link:- https://www.codechef.com/JAN19A/problems/FANCY

#include <bits/stdc++.h>
 using namespace std;

int main()
{
 
  int tests;
  cin>>tests;
  string s;
  cin.ignore();
  while(tests--)
  { 
    bool yes=false;
    string s,out;
    stringstream ss;
    getline(cin,s);
    ss<<s;
    while(ss>>out)
    {
        if(out=="not")
          yes=true;
    }
    yes?cout<<"Real Fancy\n":cout<<"regularly fancy\n";
  }

  return 0; 
}   
