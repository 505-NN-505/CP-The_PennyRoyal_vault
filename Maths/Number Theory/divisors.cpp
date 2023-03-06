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

vector<ll> divs;
void divisors(ll n) {
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			divs.emplace_back(i);
			if (i != n / i) divs.emplace_back(n / i);
		}
	}
}

void solve(void) {
	divisors(36);
	for (auto i : divs) {
		cout << i << ' ';
	}
	cout << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}