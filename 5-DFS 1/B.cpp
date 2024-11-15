#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<vector<int> > g(maxn);

bool used[maxn];

vector<vector<int> > a;

void dfs(int v) {
    used[v] = 1;
    a.back().push_back(v);

    for (auto now : g[v]) {
        if (!used[now])
            dfs(now);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            a.push_back({});
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << '\n';

    for (auto now : a) {
        cout << now.size() << '\n';

        sort(now.begin(), now.end());

        for (auto neir : now) {
            cout << neir + 1 << ' ';
        }
        cout << '\n';
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