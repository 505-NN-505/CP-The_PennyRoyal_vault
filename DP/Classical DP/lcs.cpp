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
    string s, t; cin >> s >> t;
    int n = size(s), m = size(t);
    vector<vector<int>> lcs(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
            lcs[i][j] = max({lcs[i][j], lcs[i - 1][j], lcs[i][j - 1]});
        }
    }
    
    string ans = "";
    
    int i = n, j = m;
    while (i and j) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--, j--;
            continue;
        }
        if (lcs[i - 1][j] > lcs[i][j - 1]) i--;
        else j--;
        
    }
    
    reverse(ans.begin(), ans.end());
    
    cout << lcs[n][m] << '\n';
    cout << ans << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}