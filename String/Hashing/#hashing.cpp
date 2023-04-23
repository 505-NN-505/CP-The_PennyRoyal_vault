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
using pll = pair<ll, ll>;

namespace hashing {
    const int nmax = 2e5 + 1;
    const pll base = {211, 277};
    const pll mod = {127657753, 987654319};
    const pll ibase = {12705274, 802246288};
    
    #define ff first
    #define ss second
    
    pll pb[nmax];
    
    pll operator+(const pll& a, int x)    {return {a.ff + x, a.ss + x};}
    pll operator-(const pll& a, int x)    {return {a.ff - x, a.ss - x};}
    pll operator*(const pll& a, int x)    {return {a.ff * x, a.ss * x};}
    pll operator+(const pll& a, pll x)    {return {a.ff + x.ff, a.ss + x.ss};}
    pll operator-(const pll& a, pll x)    {return {a.ff - x.ff, a.ss - x.ss};}
    pll operator*(const pll& a, pll x)    {return {a.ff * x.ff, a.ss * x.ss};}
    pll operator%(const pll& a, pll m)    {return {a.ff % m.ff, a.ss % m.ss};}
    
    void hashPre() {
        pb[0] = {1, 1};
        for (int i = 1; i < nmax; i++) {
            pb[i] = (pb[i - 1] * base) % mod;
        }
    }
    
    pll hash(string &s) {
        pll ans = {0, 0};
        for (int i = 0; i < s.size(); i++) {
            ans = (ans * base + s[i]) % mod;
        }
        return ans;
    }
    
    struct hashed_string {
        vector<pll> fh, rh;
        string s;
        int n = 0;
        void computeHash(vector<pll> &h, bool rev) {
            h.resize(n + 1);
            h[0] = {0, 0};
            for (int i = 1; i <= n; i++) {
                h[i] = (h[i - 1] * base + (!rev ? s[i - 1] : s[n - i])) % mod;
            }
        }
        hashed_string(const string& s, bool rev = false) {
            n = s.size();
            this->s = s;
            computeHash(fh, false);
            if (rev) computeHash(rh, true);
        }
        inline pll getHash(int l, int r) {
            return (fh[r] + (mod - fh[l - 1]) * pb[r - l + 1]) % mod;
        }
        inline pll getRevHash(int l, int r) {
            int t = l;
            l = n - r + 1, r = n - t + 1;
            return (rh[r] + (mod - rh[l - 1]) * pb[r - l + 1]) % mod;
        }
        inline pll append(pll &cur, char c) {
            return (cur * base + c) % mod;
        }
        inline pll prepend(pll &cur, char c, int k) {
            return (pb[k] * c + cur) % mod;
        }
        inline pll replace(pll &cur, int i, char a, char b) {
            return cur + pb[i] * (mod + (b - a)) % mod;
        }
        inline pll concat(pll &l, pll &r, int k) {
            return (l * pb[k] + r) % mod;
        }
        bool isPal(int l, int r) {
            if (l < 1 || r > n) return false;
            return getHash(l, r) == getRevHash(l, r);
        }
    };
}

using namespace hashing;

void solve(void) {
    
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    hashPre();
    
    solve();

    return 0;
}