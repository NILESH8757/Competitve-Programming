// taken from Ashishgup's library

typedef struct data
{
	data* bit[2];
	int cnt = 0;
}trie;

trie* head;

void insert(int x)
{
	trie* cur = head;
	for(int i=30;i>=0;i--)
	{
		int b = (x>>i) & 1;
		if(!cur->bit[b])
			cur->bit[b] = new trie();
		cur = cur->bit[b];
		cur->cnt++;
	}
}

void remove(int x)
{
	trie* cur = head;
	for(int i=30;i>=0;i--)
	{
		int b = (x>>i) & 1;
		cur = cur->bit[b];
		cur->cnt--;
	}
}

int maxxor(int x)
{
	trie* cur = head;
	int ans = 0;
	for(int i=30;i>=0;i--)
	{
		int b = (x>>i)&1;
		if(cur->bit[!b] && cur->bit[!b]->cnt>0)
		{
			ans += (1LL<<i);
			cur = cur->bit[!b];
		}
		else
			cur = cur->bit[b];
	}
	return ans;
}

// problem : https://codeforces.com/problemset/problem/706/D
// Probme 2 : https://www.codechef.com/CDCRFT14/problems/SUBBXOR [ count of subarrays with xor less than k ]
// Solution 2 : https://www.codechef.com/viewsolution/27949729

// Problem 3: https://www.spoj.com/problems/ADAINDEX/
// Solution 3: 
#include<bits/stdc++.h>
using namespace std;
 
typedef struct data{
    data* next[26];
    int cnt = 0;
} trie;
trie* head;
 
void trie_insert(string &s){
    trie* cur = head;
    for(char c: s){
        int idx = c - 'a';
        if(!cur->next[idx])
			cur->next[idx] = new trie();
		cur = cur->next[idx];
		cur->cnt++;
    }
}
 
int trie_count_prefix(string &s){
    trie* cur = head;
    int ans = INT_MAX;
    for(char c: s){
        int idx = c - 'a';
        if(cur->next[idx] != NULL){
          cur = cur->next[idx];
          ans = min(ans, cur->cnt);
        } else {
            ans = 0;
            break;
        }
    }
    return ans;
}
int main(){
   int n, q;
   string s;
   cin >> n >> q;
   head = new trie();
   for(int i = 0; i < n; i++){
       cin >> s;
       trie_insert(s);
   }
   while(q--){
       cin >> s;
       int ans = trie_count_prefix(s);
       cout << ans << "\n";
   }
   return 0;
} 
