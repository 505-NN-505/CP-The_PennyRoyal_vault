// https://cses.fi/problemset/task/1636

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

const int MOD = 1000000007;

void solve(void) {
	int n, x; cin >> n >> x;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    /*
    change[y] -> the number of distinct ordered ways to make y coins
    		using the coins upto index i
    */
    vector<int> change(x + 1, 0);
    change[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int y = 1; y <= x; y++) {
            if (y >= c[i]) {
                change[y] = (1ll * change[y] + change[y - c[i]]) % MOD;
            }
        }
    }
    cout << change[x] << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}