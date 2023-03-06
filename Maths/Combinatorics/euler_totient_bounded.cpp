#include <bits/stdc++.h>

/*
@uthor: Nasrum Nur
---------------------------
code n drink Pennyroyal tea
*/

#ifdef Pennyroyal
#include <debug.h>
#else
#define debug(...)
#define sdebug(...)
#endif

using namespace std;
using ll = long long;

vector<pair<ll, int>> pf;
void primeFactorize(ll n) {
    pf.clear();
    for (ll i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt) pf.push_back({i, cnt});
    }
    if (n > 1) {
        pf.push_back({n, 1});
    }
}

/*
How many numbers are coprime to n upto r?
*/
void solve(void) {
	int n = 30, r = 7;
	primeFactorize(n);
	int m = size(pf);
	int phib = 0;
	for (int j = 1; j < (1 << m); j++) {
		int multiple = 1, bits = 0;
		for (int i = 0; i < m; i++) {
			if ((1 << i) & j) {
				multiple *= pf[i].first;
				bits++;
			}
		}
		int cnt = r / multiple;
		if (bits & 1) {
			phib += cnt;
		}
		else {
			phib -= cnt;
		}
	}
	cout << max(0, r - phib) << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}