#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> adun(n);
    for (int i = 0; i < n; ++i) {
        cin >> adun[i];
    }
    sort(adun.begin(), adun.end());
    cout << adun[k - 1];
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