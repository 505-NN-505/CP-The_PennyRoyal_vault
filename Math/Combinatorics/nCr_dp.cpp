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

const int nmax = 1e4 + 1;
const int mod = 1000000007;

int nCr[nmax + 1][nmax + 1];
void gen_ncr(int n) {
	nCr[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % mod;
		}
	}
}

void solve(void) {
	cout << nCr[4][2] << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    gen_ncr(nmax);
    solve();

    return 0;
}