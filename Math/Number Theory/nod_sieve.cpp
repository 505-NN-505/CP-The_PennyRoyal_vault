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

const int nmax = 2e5 + 1;
int nod[nmax + 1];

void sieve_nod(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			nod[j]++;
		}
	}
}

void solve(void) {
	cout << nod[36] << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve_nod(nmax);
    solve();

    return 0;
}