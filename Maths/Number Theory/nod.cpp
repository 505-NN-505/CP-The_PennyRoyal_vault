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

int nod(ll n) {
	int res = 0;
	for(ll i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			if(i == n / i) res++;
			else res += 2;
		}
	}
	return res;
}

void solve(void) {
	cout << nod(36) << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}