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

const int mod = 1000000007;

int egcd(int a, int b, int& x, int& y) {
	if (b == 0) {
    	x = 1, y = 0;
		return a;
	}
	int x1, y1, d;
	d = egcd(b, a % b, x1, y1);
	x = y1, y = x1 - y1 * (a / b);
	return d;
}

void solve(void) {
	int a = 6, inv, y;
	egcd(a, mod, inv, y); // 166666668
	cerr << inv << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}