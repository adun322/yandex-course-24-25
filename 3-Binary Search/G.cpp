//
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n, x, y;
    cin >> n >> x >> y;
    long long l = 1, r = 1e18, mid;
    while (l != r) {
        mid = (l + r) / 2;
        mid -= min(x, y);
        if (mid < 0) {
            l = mid + 1 + min(x, y);
            continue;
        }
        long long copys = 1;
        copys += mid / x + mid / y;
        if (copys < n) {
            l = mid + 1 + min(x, y);
        } else {
            r = mid + min(x, y);
        }
    }
    cout << l;
}
//*/