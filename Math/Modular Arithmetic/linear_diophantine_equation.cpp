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

pair<int, int> diophantine(int a, int b, int c) {
	int x, y, g = egcd(a, b, x, y);
	x *= c / g, y *= c / g;
	return {x, y};
}

void solve(void) {
	int a = 12, b = 98, c = 60;
	auto sol = diophantine(a, b, c);
	cerr << sol.first << ' ' << sol.second << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}