#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


long long query(long long x) {
    cout << "? " << x << '\n';
    cout.flush();

    long long answer;
    cin >> answer;
    return answer;
}

void solve() {
    long long n;
    cin >> n;

    long long l = 1, r = n;

    while (l + 1 < r) {
        long long mid = (l + r) / 2;

        if (!query(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << "! " << l << '\n';
    cout.flush();
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