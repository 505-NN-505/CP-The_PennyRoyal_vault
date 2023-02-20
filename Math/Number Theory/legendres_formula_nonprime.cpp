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

int legend(int n, int p) {
    int x = 0;
    while (n > 1) {
        n /= p;
        x += n;
    }
    return x;
}

vector<pair<ll, int>> pf;
void primeFactorize(ll n) {
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

// returns the largest power of a number m that divides n!
void solve(void) {
    int m, n;
    cin >> m >> n;

    pf.clear();
    primeFactorize(m);

    int ans = INT_MAX;
    for (int i = 0; i < pf.size(); i++) {
        ans = min(ans, legend(n, pf[i].first) / pf[i].second);
    }

    if (!ans || ans == INT_MAX) cout << "Impossible to divide\n";
    else cout << ans << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}