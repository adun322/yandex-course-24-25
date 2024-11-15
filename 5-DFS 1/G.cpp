#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
vector<vector<int> > g(maxn);
int c[maxn];
bool used[maxn];
int cnt = 0;

void dfs(int v) {
    used[v] = 1;
    cnt++;

    for (auto now : g[v]) {
        if (!used[now]) {
            dfs(now);
        }
    }
}

void solve() {
    int n, m, t;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n != m + 1) {
        cout << "NO\n";
        return;
    }

    dfs(0);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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