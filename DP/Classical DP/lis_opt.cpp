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
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    vector<int> dp;
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(begin(dp), end(dp), a[i]);
        if (it == end(dp)) {
            dp.push_back(a[i]);
        }
        else {
            *it = a[i];
        }
    }
    
    cout << size(dp) << '\n';
}
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}