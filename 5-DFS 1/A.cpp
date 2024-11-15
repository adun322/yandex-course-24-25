#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    int ma[100][100] = {};

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ma[u][v] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ma[i][j] << ' ';
        } cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;

    // cin >> t;

#ifdef LOCAL
    auto start_time = clock();
#endif

    while (t--) solve();

#ifdef LOCAL
    auto end_time = clock();

    auto diff = end_time - start_time;

    cout << "\nWorking time: " << diff;
#endif
}