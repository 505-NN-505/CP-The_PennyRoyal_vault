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

int power(int x, int n, const int m) {
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

const int nmax = 2e5 + 1;
const int mod = 1000000007;
int pod[nmax + 1];

void sieve_pod(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			pod[j]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		int nod = pod[i];
		pod[i] = power(i, pod[i] / 2, mod);
		if (nod & 1) pod[i] = (pod[i] * (int)sqrt(i)) % mod;
	}
}

void solve(void) {
	cout << pod[4] << '\n';
	cout << pod[6] << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve_pod(nmax);
    solve();

    return 0;
}