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

const int nmax = 2e5 + 1;

namespace hashing {
    const pll base = {211, 277};
    const pll mod = {127657753, 987654319};
    const pll ibase = {12705274, 802246288};
    
    #define ff first
    #define ss second
    
    pll pb[nmax], ipb[nmax];
    
    pll operator+(const pll& a, int x)    {return {a.ff + x, a.ss + x};}
    pll operator-(const pll& a, int x)    {return {a.ff - x, a.ss - x};}
    pll operator*(const pll& a, int x)    {return {a.ff * x, a.ss * x};}
    pll operator+(const pll& a, pll x)    {return {a.ff + x.ff, a.ss + x.ss};}
    pll operator-(const pll& a, pll x)    {return {a.ff - x.ff, a.ss - x.ss};}
    pll operator*(const pll& a, pll x)    {return {a.ff * x.ff, a.ss * x.ss};}
    pll operator%(const pll& a, pll m)    {return {a.ff % m.ff, a.ss % m.ss};}
    
    typedef pll node;

    struct seg_tree {
        #define lc (n << 1)
        #define rc ((n << 1) | 1)
        const node neutral = {0, 0};

        vector<node> a, t;

        void reset(vector<pll> &a, int n) {
            this->a = a;
            t.assign(4 * nmax, {0, 0});
            build(1, 1, n);
        }

        inline node merge(node a, node b) {
            return (a + b) % mod;
        }

        inline void pull(int n) {
            t[n] = (t[lc] + t[rc]) % mod;
        }

        void build(int n, int b, int e) {
            if (b == e) {
                t[n] = a[b];
                return;
            }
            int mid = (b + e) >> 1;
            build(lc, b, mid);
            build(rc, mid + 1, e);
            pull(n);
        }

        void update(int n, int b, int e, int i, pll x) {
            if (b > i || e < i) return;
            if (b == e && b == i) {
                t[n] = x;
                return;
            }
            int mid = (b + e) >> 1;
            update(lc, b, mid, i, x);
            update(rc, mid + 1, e, i, x);
            pull(n);
        }

        node query(int n, int b, int e, int i, int j) {
            if (b > j || e < i) return neutral;
            if (b >= i && e <= j) return t[n];
            int mid = (b + e) >> 1;
            return merge(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
        }
    } fst, rst;
    
    void hashPre() {
        pb[0] = ipb[0] = {1, 1};
        for (int i = 1; i < nmax; i++) {
            pb[i] = (pb[i - 1] * base) % mod;
            ipb[i] = (ipb[i - 1] * ibase) % mod;
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
                h[i] = (pb[i - 1] * (!rev ? s[i - 1] : s[n - i])) % mod;
            }
        }
        hashed_string(const string& s, bool rev = false) {
            n = s.size();
            this->s = s;
            computeHash(fh, false);
            fst.reset(fh, n);
            if (rev) {
                computeHash(rh, true);
                rst.reset(rh, n);
            }
        }
        void update(int index, char ch) {
            fh[index] = pb[index - 1] * ch % mod;
            rh[n - index + 1] = pb[n - index] * ch % mod;
            fst.update(1, 1, n, index, fh[index]);
            rst.update(1, 1, n, n - index + 1, rh[n - index + 1]);
        }
        inline pll getHash(int l, int r) {
            pll hash = fst.query(1, 1, n, l, r);
            hash = ipb[l - 1] * hash % mod;
            return hash;
        }
        inline pll getRevHash(int l, int r) {
            int t = l; l = n - r + 1, r = n - t + 1;
            pll hash = rst.query(1, 1, n, l, r);
            hash = ipb[l - 1] * hash % mod;
            return hash;
        }
    };
}

using namespace hashing;

void solve(void) {
    int n, m; cin >> n >> m;
    string s; cin >> s;;
    
    hashed_string hs(s, true);

    for (int i = 0; i < m; i++) {
        int op; cin >> op;
        if (op == 1) {
            int k; char x; cin >> k >> x;
            hs.update(k, x);
        }
        else {
            int a, b; cin >> a >> b;
            if (hs.getHash(a, b) == hs.getRevHash(a, b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    hashPre();
    
    solve();

    return 0;
}