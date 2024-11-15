#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    int n;
    cin >> n;
    set<vector<int>> q;
    int x, cur = 1;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        q.insert({max(1, 1000 - x), i + 1, max(1, 1000 - x)});
    }
    int t = 0, res = -1;
    while (true) {
        auto a = *q.begin();
        if (abs(cur - a[1]) <= abs(t - a[0])) {
            q.erase(q.begin());
            q.insert({a[0] + max(1, a[2] - 1), a[1], max(1, a[2] - 1)});
            cur = a[1];
            t = a[0];
        } else {
            res = a[0];
            break;
        }
    }
    cout << res;
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