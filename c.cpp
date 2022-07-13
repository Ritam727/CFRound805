// code by Ritam
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vll vector<ll>
#define tests int t; cin >> t; while(t--)
#define pb push_back
using namespace std;

struct customHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x^(x >> 30))*0xbf58476d1ce4e5b9;
        x = (x^(x >> 27))*0x94d049bb133111eb;
        return x^(x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};

int gtx(vll& v, ll x) {
	int s = 0, e = v.size()-1, ans = -1;
	while(s <= e) {
		int m = s+(e-s)/2;
		if(v[m] >= x) {
			ans = m;
			e = m-1;
		} else {
			s = m+1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		int n, q; cin >> n >> q;
		unordered_map<int, vll, customHash> m;
		ll ma = 0, mi = 1e9+7;
		for(int i = 0; i < n; i++) {
			ll x; cin >> x;
			m[x].pb(i);
			ma = max(ma, x);
			mi = min(mi, x);
		}
		while(q--) {
			ll a, b; cin >> a >> b;
			if(ma < a || ma < b || mi > a || mi > b) {
				cout << "NO\n";
			} else {
				if(!m.count(a) || !m.count(b)) {
					cout << "NO\n";
					continue;
				}
				if(gtx(m[b], m[a][0]) != -1) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
			}
		}
	}
	return 0;
}
