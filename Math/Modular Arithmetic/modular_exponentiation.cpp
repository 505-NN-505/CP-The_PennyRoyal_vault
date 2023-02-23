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

const int mod = 1000000007;

int power(ll x, ll n, const int m) {
    int res = 1 % m;
    x %= m;
    if (x < 0) x += m;
    while (n) {
        if (n & 1) res = (1ll * res * x) % m;
        x = (1ll * x * x) % m;
        n >>= 1;
    }
    return res;
}

void solve(void) {
	cerr << power(1e18, 1e18, mod) << '\n'; //504853526
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}