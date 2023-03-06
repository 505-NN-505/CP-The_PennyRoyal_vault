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

// returns the largest power of prime p that divides n!
ll legend(ll n, ll p) {
	ll x = 0;
	while (n > 1) {
		n /= p;
		x += n;
	}
	return x;
}

void solve(void) {
	cout << legend(5, 3);
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}