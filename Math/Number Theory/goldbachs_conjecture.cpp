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
void sieve(int n) {
    mark[0] = true;
    for (int i = 3; i * i <= n; i += 2) {
        if (!mark[i >> 1]) {
            for (int j = i * i; j <= n; j += i * 2)
                mark[j >> 1] = true;
        }
    }
}

void gold_conj(int n) {
    if (!mark[(n - 2) >> 1]) {
        cout << 2 << ' ' << n - 2 << '\n';
    }
    for (int i = 3; i <= n / 2; i += 2) {
        if (!mark[i >> 1] && !mark[(n - i) >> 1]) {
            cout << i << " " << n - i << '\n';
        }
    }
}

void solve(void) {
    gold_conj(6);
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(nmax);
    solve();

    return 0;
}