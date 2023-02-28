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

ll nCr(int n, int r) {
	ll res = 1;
	for (int i = 1; i <= r; i++) {
		res = res * (n - i + 1) / i;
	}
	return res;
}

void solve(void) {
	cout << nCr(4, 2) << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}