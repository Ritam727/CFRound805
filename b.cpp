// code by Ritam
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vll vector<ll>
#define tests int t; cin >> t; while(t--)
#define pb push_back
using namespace std;

bool check(vi& arr) {
	int c = 0;
	for(int i = 0; i < 26; i++)
		c += (arr[i] > 0);
	return c <= 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		string s; cin >> s;
		int i = 0, n = s.length(), ans = 0;
		while(i < n) {
			int j = i+1;
			vi arr(26, 0);
			arr[s[i]-'a']++;
			while(j < n) {
				arr[s[j]-'a']++;
				if(!check(arr)) break;
				j++;
			}
			ans++;
			i = j;
		}
		cout << ans << "\n";
	}
	return 0;
}
