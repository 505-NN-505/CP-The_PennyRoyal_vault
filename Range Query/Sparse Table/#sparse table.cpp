#include <bits/stdc++.h>

// code n drink Pennyroyal tea
#ifdef Pennyroyal
#include <debug.h>
#else
#define debug(...)
#define sdebug(...)
#endif

using namespace std;
using ll = long long;

const int nmax = 1e6 + 1;

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
		int query(int l, int r) {
			int i = log2_floor(r - l + 1);
			return min(st[i][l], st[i][r - (1 << i) + 1]);
		}

		// cascade when the operation is not overlap friendly
		// an operation is not overlap friendly when:
		// f(f(a, b), f(b, c)) != f(a, f(b, c))
		inline int cascade_query(int a, int b) {
			return add_sparse(a, b);
		}
		ll add_sparse(int l, int r) {
			ll sum = 0;
			for (int i = k; i >= 0; i--) {
				if ((1 << i) <= r - l + 1) {
					sum += st[i][l];
					l += (1 << i);
				}
			}
			return sum;
		}
	};
}

void solve(void) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    
    stb::sparse_table st(a);
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}