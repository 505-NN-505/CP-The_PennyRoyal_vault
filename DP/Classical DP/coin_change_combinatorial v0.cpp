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

void solve(void) {
	 /*
    Given n(number of total coins), w(exchange currency). 
    Find the total number of ways to exchange w.
    (Each coin can be used infinitely)
    Input:
    3 9
	2 3 5
	Output:
	8
    */
    int n, w;
    cin >> n >> w;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<int> change(w + 1); change[0] = 1;
    for (int i = 0; i <= w; i++) {
        for (auto coin : c) {
            if (i - coin >= 0) {
                change[i] += change[i - coin];
                change[i] %= mod;
            }
        }
    }
    
    cout << change[w] << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}