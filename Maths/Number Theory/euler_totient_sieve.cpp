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
int phi[nmax + 1];

void sieve_etf(int n) {
	for(int i = 1; i <= n; i++) phi[i] = i;
	for(int i = 2; i <= n; i++) {
		if(phi[i] == i)
			for(int j = i; j <= n; j += i) 
				phi[j] -= (phi[j] / i);
    }
}

void solve(void) {
	cerr << phi[4] << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve_etf(nmax);
    solve();

    return 0;
}