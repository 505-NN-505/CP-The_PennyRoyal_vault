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
using ll = long long;

bool is_prime(ll n) {
    if (n == 2) return 1;
    else if (n < 2) return 0;
    else if (n % 2 == 0) return 0;
    for(ll i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void solve(void) {
    cerr << is_prime(101) << '\n';
    cerr << is_prime(1) << '\n';
    cerr << is_prime(57) << '\n';  
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}