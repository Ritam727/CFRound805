// code by Ritam
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vll vector<ll>
#define tests int t; cin >> t; while(t--)
#define pb push_back
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	tests {
		string s; ll p; cin >> s >> p;
		vi arr(26, 0); int c = 0, n = s.length();
		for(int i = 0; i < n; i++) {
			arr[s[i]-'a']++;
			c += (s[i]-'a'+1);
		}
		if(c <= p) {
			cout << s << "\n";
			continue;
		}
		for(int i = 25; i >= 0; i--) {
			if(c-arr[i]*(i+1) <= p) {
				int temp = arr[i];
				arr[i] -= (c-p+i)/(i+1);
				c -= (temp-arr[i])*(i+1);
				break;
			} else {
				c -= arr[i]*(i+1);
				arr[i] = 0;
			}
		}
		for(int i = 0; i < n; i++) {
			if(arr[s[i]-'a']) {
				cout << s[i];
				arr[s[i]-'a']--;
			}
		}
		cout << "\n";
	}
	return 0;
}
