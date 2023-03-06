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

void solve(void) {
    /*
    Given n(number of total coins), w(exchange currency). 
    Find the total number of ways to exchange w.
    (Each coin can be used atmost once)
    */
    int n, w;
    cin >> n >> w;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];

    vector<vector<int>> change(n + 1, vector<int> (w + 1, 0));
    for (int i = 0; i <= n; i++) change[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (j - c[i] >= 0) {
                change[i][j] += change[i - 1][j - c[i]];
            }
            change[i][j] += change[i - 1][j];
        }
    }

    cout << change[n][w];
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}