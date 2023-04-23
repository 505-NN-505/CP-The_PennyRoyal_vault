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

const int inf = 1e9 + 505;

void solve(void) {
	string s, t; cin >> s >> t;
	int n = size(s), m = size(t);
	vector<vector<int>> distance(n + 1, vector<int> (m + 1, inf));
	distance[0][0] = 0;
	for (int i = 1; i <= n; i++) distance[i][0] = i;
	for (int i = 1; i <= m; i++) distance[0][i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int op_insert = distance[i][j - 1] + 1;
			int op_remove = distance[i - 1][j] + 1;
			int op_modify = distance[i - 1][j - 1] + (s[i - 1] != t[j - 1]);
			distance[i][j] = min({op_insert, op_remove, op_modify});
		}
	}
	cout << distance[n][m] << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}