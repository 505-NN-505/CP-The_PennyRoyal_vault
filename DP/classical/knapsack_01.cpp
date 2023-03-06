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
	int n, x; cin >> n >> x;
    vector<int> h(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
 
    vector<vector<int>> score(n + 1, vector<int> (x + 1, 0));
    /*
    score[i][j] -> the maximum number of values upto index i 
                having weights atmost j
    */
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            score[i][j] = score[i - 1][j];
            if (j - h[i] >= 0) {
                score[i][j] = max(score[i][j], s[i] + score[i - 1][j - h[i]]);
            }
        }
    }
 
    cout << score[n][x];
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}