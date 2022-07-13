// code by Ritam
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vll vector<ll>
#define tests int t; cin >> t; while(t--)
#define pb push_back
using namespace std;

ll power(ll n, int k) {
	if(k == 0) return 1LL;
	ll h = power(n, k/2);
	ll p = (h*h);
	if(k&1) return (n*p);
	else return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		ll n; cin >> n;
		ll k = 0, temp = n;
		while(n) {
			k++;
			n /= 10;
		}
		cout << temp-power(10, k-1) << "\n";
	}
	return 0;
}
