#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
vector<vector<int> > g(maxn);

bool used[maxn];
bool c[maxn];

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

    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            q.push(i);

            while (!q.empty()) {
                int v = q.front();
                q.pop();
                used[v] = 1;

                for (auto now : g[v]) {
                    if (used[now]) {
                        if (c[now] == c[v]) {
                            cout << "NO";
                            return;
                        }
                    } else {
                        used[v] = 1;
                        q.push(now);
                        c[now] = !c[v];
                    }
                }
            }
        }
    }

    cout << "YES";
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