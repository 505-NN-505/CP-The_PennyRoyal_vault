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
vector<int> divs[nmax + 1];

void sieve_divs(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			divs[j].emplace_back(i);
		}
	}
}

void solve(void) {
	for (auto i : divs[36]) {
		cout << i << ' ';
	}
	cout << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve_divs(nmax);
    solve();

    return 0;
}