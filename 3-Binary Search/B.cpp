#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    long double c;
    cin >> c;
    long double l = 0, r = 1e9, m;
    for (int i = 0; i < 1000; ++i) {
        m = (l + r) / 2;
        long double x = m * m + sqrtl(m);
        if (x < c) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << "\n";
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