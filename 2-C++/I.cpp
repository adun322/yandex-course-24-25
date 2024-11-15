#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, pair<int, int>>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second.first;
        a[i].second.second = i;
    }
    vector<int> g(n);
    for (int i = 0; i < n; ++i) g[i] = i;
    sort(a.begin(), a.end());
    multiset<pair<int, int>> chisla;
    int cnt = n;
    vector<int> superobhod;
    for (auto now : a) {
        superobhod.push_back(now.second.second);
        auto u = chisla.lower_bound({now.first, -1e9});
        if (u != chisla.begin()) {
            --u;
            g[u->second] = now.second.second;
            chisla.erase(u);
            cnt--;
        }
        chisla.insert({now.first + now.second.first - 1, now.second.second});
    }
    cout << cnt << '\n';
    vector<bool> used(n, 0);
    for (auto i : superobhod) {
        if (used[i]) continue;
        int j;
        for (j = i; g[j] != j; j = g[j]) {
            cout << j + 1 << ' ';
            used[j] = 1;
        }
        used[j] = 1;
        cout << j + 1 << ' ';
    }
}


signed main() {
    cout << fixed << setprecision(20);
#ifdef LOCAL
    freopen("C:\\Users\\adun\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\adun\\Desktop\\c++\\output.txt", "w", stdout);
#else
    //freopen("palindrome.in", "r", stdin);
    //freopen("palindrome.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#endif
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
}