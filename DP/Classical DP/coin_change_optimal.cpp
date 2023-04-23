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
    Find the minimum number of coins needed to exchange w.
    (Each coin can be used infinitely)
    Input:
    3 11
	1 5 7
    Output:
    3
	1 5 5 
    */
    int n, w;
    cin >> n >> w;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<int> change(w + 1, INT_MAX); change[0] = 0;
    vector<int> link(w + 1, 0);
    
    for (int i = 0; i <= w; i++) {
        for (auto coin : c) {
            if (i - coin >= 0 && change[i - coin] + 1 < change[i]) {
                change[i] = change[i - coin] + 1;
                link[i] = coin;
            }
        }
    }
    
    cout << change[w] << '\n';
    
    while (link[w] > 0) {
        cout << link[w] << ' ';
        w -= link[w];
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}