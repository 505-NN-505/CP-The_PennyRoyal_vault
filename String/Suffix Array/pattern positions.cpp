#include <bits/stdc++.h>

// code n drink Pennyroyal tea
#ifdef Pennyroyal
#include <debug.h>
#else
#define debug(...)
#define sdebug(...)
#endif

using namespace std;

const int nmax = 1e5 + 1;

namespace stb {
    const int k = 25;
    int st[k + 1][nmax];
    struct sparse_table {
        sparse_table(const vector<int> &a) {
            int n = a.size();
            copy(begin(a), end(a), st[0]);
            for (int i = 1; i <= k; i++) {
                for (int j = 0; j + (1 << i) <= n; j++) {
                    st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                }
            }
        }
        int log2_floor(unsigned long long i) {
            return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
        }
        inline int f(int a, int b) {
            return min(a, b);
        }
        // 0-based index
        int query(int l, int r) {
            int i = log2_floor(r - l + 1);
            return min(st[i][l], st[i][r - (1 << i) + 1]);
        }
    };
}

namespace sar {
    vector<vector<int>> c;
    vector<int> sort_cyclic_shifts(const string &s) {
        int n = s.size();
        const int alphabet = 256;
        vector<int> p(n), cnt(alphabet, 0);

        c.clear();
        c.emplace_back();
        c[0].resize(n);

        for (int i = 0; i < n; i++)         cnt[s[i]]++;
        for (int i = 1; i < alphabet; i++)  cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++)         p[--cnt[s[i]]] = i;

        c[0][p[0]] = 0;
        int classes = 1;

        for (int i = 1; i < n; i++) {
            if (s[p[i]] != s[p[i - 1]]) classes++;
            c[0][p[i]] = classes - 1;
        }

        vector<int> pn(n), cn(n);
        cnt.resize(n);

        for (int h = 0; (1 << h) < n; h++) {
            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0)  pn[i] += n;
            }

            fill(cnt.begin(), cnt.end(), 0);

            /// radix sort
            for (int i = 0; i < n; i++)         cnt[c[h][pn[i]]]++;
            for (int i = 1; i < classes; i++)   cnt[i] += cnt[i-1];
            for (int i = n - 1; i >= 0; i--)    p[--cnt[c[h][pn[i]]]] = pn[i];
            
            cn[p[0]] = 0;
            classes = 1;

            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {c[h][p[i]], c[h][(p[i] + (1<<h))%n]};
                pair<int, int> prev = {c[h][p[i-1]], c[h][(p[i-1] + (1<<h))%n]};
                if (cur != prev) ++classes;
                cn[p[i]] = classes - 1;
            }

            c.push_back(cn);
        }
        return p;
    }
    
    vector<int> suffix_array_construction(string s) {
        s += "!";
        auto sorted_shifts = sort_cyclic_shifts(s);
        sorted_shifts.erase(sorted_shifts.begin());
        return sorted_shifts;
    }
}

void solve(void) {
    string s; cin >> s;
    int n = s.size();
    
    auto sa = sar::suffix_array_construction(s);
    stb::sparse_table st(sa);

    s = s + '!' + s;

    int k; cin >> k;
    while (k--) {
        string p; cin >> p;
        int len = p.size();
        
        int lo = 0, hi = n - 1, mid, l = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (s.substr(sa[mid], len) <= p) {
                l = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        
        if (l == -1) {
            cout << -1 << '\n';
            continue;
        }
        
        lo = 0, hi = n - 1;
        int r = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (s.substr(sa[mid], len) >= p) {
                r = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        
        if (s.substr(sa[r], len) != p) {
            cout << -1 << '\n';
            continue;
        }
        
        if (l > r) swap(l, r);
        
        cout << st.query(l, r) + 1 << '\n';
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}