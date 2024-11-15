#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
vector<vector<int> > g(maxn);
int c[maxn];
bool used[maxn];

void dfs(int v, int color) {
    used[v] = 1;
    c[v] = color;

    for (auto now : g[v]) {
        if (!used[now]) {
            dfs(now, color);
        }
    }
}

void solve() {
    int n, m, t;
    cin >> n >> m >> t;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u == t || v == t) {
            continue;
        }
        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, cnt++);
        }
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;

        --u;
        --v;

        if (c[u] == c[v]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
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