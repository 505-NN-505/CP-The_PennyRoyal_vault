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

bool mark[(nmax >> 1) + 1];
vector<pair<int, int>> tp;
void sieve(int n) {
    mark[0] = true;
    for (int i = 3; i * i <= n; i += 2) {
        if (!mark[i >> 1]) {
            for (int j = i * i; j <= n; j += i * 2)
                mark[j >> 1] = true;
        }
    }
    for (int i = 3; i <= n; i += 2) {
        if (!mark[i] and !mark[i + 2]) {
            tp.push_back({i, i + 2});
        }
    }
}

void solve(void) {
    cout << tp[2].first << ' ' << tp[2].second;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(nmax);
    solve();

    return 0;
}