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

void solve(void) {
    primeFactorize(24);
    for (auto x : pf)
        cout << x.first << ' ' << x.second << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}