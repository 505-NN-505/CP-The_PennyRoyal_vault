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

const int nmax = 1e5 + 1;
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
    hashed_string(string const& _s) {
        s = _s;
        n = s.size();
        build();
    }
    void build() {
        for (int i = 0; i < n; i++) {
            prefHash1[i] = 1ll * s[i] * pow1[i] % mod1;
            if (i) prefHash1[i] = (prefHash1[i] + prefHash1[i - 1]) % mod1;
            prefHash2[i] = 1ll * s[i] * pow2[i] % mod2;
            if (i) prefHash2[i] = (prefHash2[i] + prefHash2[i - 1]) % mod2;
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
};

bool check(int len, hashed_string &hs1, hashed_string &hs2) {
	set<ll> st;
	for (int i = 0; i + len < hs1.n; i++) {
		st.insert(hs1.get_hash(i, i + len));
	}
	for (int i = 0; i + len < hs2.n; i++) {
		if (st.count(hs2.get_hash(i, i + len))) {
			return true;
		}
	}
	return false;
}

int lcs(hashed_string &hs1, hashed_string &hs2) {
	int lo = 0, hi = min(hs1.n, hs2.n) - 1;
	int res = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (check(mid, hs1, hs2)) {
			res = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return res + 1;
}

void solve(void) {
	string s1, s2; cin >> s1 >> s2;
	hashed_string hs1(s1), hs2(s2);
	cout << lcs(hs1, hs2) << '\n';
}

int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precPowers();
    solve();

    return 0;
}