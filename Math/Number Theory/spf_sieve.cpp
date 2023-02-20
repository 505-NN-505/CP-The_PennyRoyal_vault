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

const int nmax = 2e6 + 1;
int spf[nmax + 1];

void sieve_spf(int n) {
    for (int i = 1; i <= n; i++) spf[i] = i;
    for (int i = 2; i <= n; i++) {
        if (spf[i] == i) {
            for(int j = i; j <= n; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
}

void solve(void) {
	for (int i = 2; i <= 20; i++) {
		cerr << spf[i] << ' ';
	}
	cerr << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve_spf(nmax);
    solve();

    return 0;
}