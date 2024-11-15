//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    unsigned long long a, k, b, m, x;
    cin >> a >> k >> b >> m >> x;
    unsigned long long l = 0, r = x / min(a, b) + 10, mid;
    while (l != r) {
        mid = l + (r - l) / 2;
        if ((mid - (mid / k)) * a + (mid - (mid / m)) * b >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("C:\\Users\\adun\\Desktop\\c++\\input.txt", "r", stdin);
    freopen("C:\\Users\\adun\\Desktop\\c++\\output.txt", "w", stdout);
#endif
    unsigned long long t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
//*/