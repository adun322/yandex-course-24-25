#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    long long n, a, b, w, h, x;
    cin >> n >> a >> b >> w >> h;
    long long l = 0, r = min(w, h), mid;
    while (l != r) {
        mid = (l + r) / 2 + 1;
        if (max((h / (a + 2 * mid)) * (w / (b + 2 * mid)), (w / (a + 2 * mid)) * (h / (b + 2 * mid))) >= n)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
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