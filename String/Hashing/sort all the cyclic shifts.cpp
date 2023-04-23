#include <bits/stdc++.h>

// Pennyroyal -> herbal for all the bugs
#ifdef Pennyroyal
#include <debug.h>
#else
#define debug(...)
#define sdebug(...)
#endif

using namespace std;
using ll = long long;

const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const int ip1 = 11181701, ip2 = 802246288; // ip = inv_mod(p, mod)

const int nmax = 2e5 + 1;
int pow1[nmax], pow2[nmax], ipow1[nmax], ipow2[nmax];

void precPowers() {
    pow1[0] = pow2[0] = ipow1[0] = ipow2[0] = 1;
    for (int i = 1; i < nmax; i++) {
        pow1[i] = 1ll * pow1[i - 1] * p1 % mod1;
        pow2[i] = 1ll * pow2[i - 1] * p2 % mod2;
        ipow1[i] = 1ll * ipow1[i - 1] * ip1 % mod1;
        ipow2[i] = 1ll * ipow2[i - 1] * ip2 % mod2;
    }
}

struct hashed_string {
    string s;
    int n, prefHash1[nmax], prefHash2[nmax];
    hashed_string() {}
    hashed_string(string const& _s) {
        reset(s);
    }
    void reset(string const &_s) {
        s = _s;
        n = s.size();
        build();
    }
    void build() {
        for (int i = 0; i < n; i++) {
            prefHash1[i] = 1ll * s[i] * pow1[i] % mod1;
            prefHash2[i] = 1ll * s[i] * pow2[i] % mod2;
            if (i) {
                prefHash1[i] = (prefHash1[i] + prefHash1[i - 1]) % mod1;
                prefHash2[i] = (prefHash2[i] + prefHash2[i - 1]) % mod2;
            }
        }
    }
    ll get_hash(int i, int j) {
        int hash1 = prefHash1[j], hash2 = prefHash2[j];
        if (i) {
            hash1 = (hash1 - prefHash1[i - 1] + mod1) % mod1;
            hash2 = (hash2 - prefHash2[i - 1] + mod2) % mod2;
        }
        hash1 = 1ll * hash1 * ipow1[i] % mod1;
        hash2 = 1ll * hash2 * ipow2[i] % mod2;
        return 1ll * hash1 * mod2 + hash2;
    }
    ll get_hash() {
        return get_hash(0, n - 1);
    }
} hs;

int lcp(int l1, int r1, int l2, int r2) {
    int lo = 0, hi = min(r1 - l1, r2 - l2);
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (hs.get_hash(l1, l1 + mid) == hs.get_hash(l2, l2 + mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans + 1;
}

int compare(int l, int r, int i, int j) {
    int len = lcp(l, r, i, j);
    int len1 = r - l + 1, len2 = j - i + 1;
    if (len1 == len2 && len == len1) return 0;
    else if (len == len1) return 1;
    else if (len == len2) return -1;
    else return (hs.s[l + len] < hs.s[i + len] ? -1 : 1);
}

bool comp(int p1, int p2) {
    int l1 = p1, r1 = l1 + (hs.n >> 1) - 1;
    int l2 = p2, r2 = l2 + (hs.n >> 1) - 1;
    return compare(l1, r1, l2, r2) == -1;
}

void solve(void) {
    string s; cin >> s;
    int n = size(s); s += s;
    hs.reset(s);
    vector<int> cycle_index;
    for (int i = 0; i + n - 1 < hs.n - 1; i++) {
        cycle_index.push_back(i);
    }
    sort(begin(cycle_index), end(cycle_index), comp);
    for (auto it : cycle_index) cout << it << ' ';
    cout << '\n';
}

int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precPowers();
    solve();

    return 0;
}