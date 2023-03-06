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

const int nmax = 2e5 + 1;
ll sod[nmax + 1];

void sieve_sod(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			sod[j] += i;
		}
	}
}

void solve(void) {
	cout << sod[36] << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve_sod(nmax);
    solve();

    return 0;
}