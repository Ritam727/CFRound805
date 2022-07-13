// code by Ritam
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vll vector<ll>
#define tests int t; cin >> t; while(t--)
#define pb push_back
using namespace std;

struct Node {
	int cnt;
	Node *nxt[2];
	
	Node() {
		cnt = 0;
		nxt[0] = nxt[1] = NULL;
	}
};

struct Trie {
	Node *head = NULL;
	
	Trie() {
		head = new Node();
	}
	
	void insert(ll x) {
		Node *cur = head;
		int hb = 31-__builtin_clz(x);
		for(int i = hb; i >= 0; i--) {
			int bit = (x >> i)&1;
			if(!(cur->nxt[bit])) cur->nxt[bit] = new Node();
			cur = cur->nxt[bit];
			cur->cnt++;
		}
	}
	
	void remove(ll x) {
		Node *cur = head;
		int hb = 31-__builtin_clz(x);
		for(int i = hb; i >= 0; i--) {
			int bit = (x >> i)&1;
			cur = cur->nxt[bit];
			cur->cnt--;
		}
	}
	
	int find(ll x) {
		Node *cur = head;
		int hb = 31-__builtin_clz(x);
		for(int i = hb; i >= 0; i--) {
			int bit = (x >> i)&1;
			if(!cur->nxt[bit] || !cur->nxt[bit]->cnt) return 0;
			cur = cur->nxt[bit];
		}
		return 1;
	}
};

void solve() {
	int n; cin >> n;
	vll a(n);
	Trie trie;
	for(ll& i : a) {
		cin >> i;
		while(!(i&1)) i >>= 1;
	}
	for(int i = 0; i < n; i++) {
		ll x; cin >> x;
		trie.insert(x);
	}
	sort(a.begin(), a.end());
	for(ll i : a) {
		if(trie.find(i)) {
			trie.remove(i);
		} else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		solve();
	}
	return 0;
}
