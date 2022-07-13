// code by Ritam
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vll vector<ll>
#define tests int t; cin >> t; while(t--)
#define pb push_back
using namespace std;

int n, q; ll timer;
vector<vi> tree, par;
vll tin, tout, dep;

void addEdge() {
	int u, v; cin >> u >> v;
	tree[u].pb(v);
	tree[v].pb(u);
}

void dfs(int u, int p, int d) {
	tin[u] = timer++;
	par[u][0] = p;
	dep[u] = d;
	for(int v : tree[u])
		if(v != p) dfs(v, u, d+1);
	tout[u] = timer++;
}

int isAncestor(int u, int v) {
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
	if(isAncestor(u, v)) return u;
	if(isAncestor(v, u)) return v;
	for(int i = 19; i >= 0; i--)
		if(par[u][i] && !isAncestor(par[u][i], v)) u = par[u][i];
	return par[u][0];
}

int dist(int u, int v) {
	int l = lca(u, v);
	return dep[u]+dep[v]-2*dep[l];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	tree.assign(n+1, vi());
	par.assign(n+1, vi(20, 0));
	dep.assign(n+1, 0);
	tin.assign(n+1, 0);
	tout.assign(n+1, 0);
	for(int i = 1; i < n; i++)
		addEdge();
	dfs(1, 0, 0);
	for(int j = 1; j < 20; j++)
		for(int i = 0; i < n; i++)
			par[i+1][j] = par[par[i+1][j-1]][j-1];
	cin >> q;
	while(q--) {
		int k; cin >> k;
		vi v(k);
		for(int& i : v)
			cin >> i;
		if((int)v.size() <= 2) {
			cout << "YES\n";
			continue;
		}
		int p = 0, q = 0, d = 0; ll ma = 0;
		for(int i : v) {
			if(ma < tin[i]) {
				ma = tin[i];
				p = i;
			}
		}
		for(int i : v) {
			if(d < dist(i, p)) {
				d = dist(i, p);
				q = i;
			}
		}
		int l = lca(p, q), poss = 1;
		for(int i = 0; i < k && poss; i++)
			poss &= ((lca(v[i], l) == l) && ((lca(v[i], p) == v[i] && lca(v[i], q) == l) || (lca(v[i], p) == l && lca(v[i], q) == v[i])));
		if(poss) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
