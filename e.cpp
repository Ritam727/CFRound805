// code by Ritam
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vll vector<ll>
#define tests int t; cin >> t; while(t--)
#define pb push_back
#define F first
#define S second
using namespace std;

int n;
vector<vi> graph;
vi color, vis, cnt;

int bipartite(int u, int d) {
	if(!vis[u]) {
		int ans = 1;
		vis[u] = 1;
		color[u] = d;
		for(int v : graph[u])
			ans &= bipartite(v, (d^1));
		return ans;
	} else {
		if(d != color[u]) return 0;
		return 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		cin >> n;
		graph.assign(n+1, vi());
		color.assign(n+1, 0);
		vis.assign(n+1, 0);
		cnt.assign(n+1, 0);
		for(int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			graph[a].pb(b);
			graph[b].pb(a);
			cnt[a]++; cnt[b]++;
		}
		int ans = 1;
		for(int i = 0; i < n; i++)
			if(!vis[i+1]) ans &= bipartite(i+1, 0);
		for(int i = 0; i < n; i++)
			ans &= (cnt[i+1] <= 2);
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
