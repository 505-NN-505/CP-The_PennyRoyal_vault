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

const int MOD = 1000000007;

void solve(void) {
	int n; cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
 
    vector<vector<int>> ways(n, vector<int> (n, 0));
 
    ways[0][0] = grid[0][0] == '.';
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!i and !j) continue;
            if (grid[i][j] == '*') continue;
            if (!i) {
                ways[i][j] = ways[i][j - 1];
                continue;
            }
            if (!j) {
                ways[i][j] = ways[i - 1][j];
                continue;
            }
            ways[i][j] = (1ll * ways[i - 1][j] + ways[i][j - 1]) % MOD;
        }
    }
 
    cout << ways[n - 1][n - 1];
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}