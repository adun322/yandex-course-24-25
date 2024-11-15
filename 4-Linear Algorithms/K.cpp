//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    multiset<long long> pon;
    vector<long long> adun(n);
    for (long long i = 0; i < n; ++i) {
        cin >> adun[i];
    }
    for (long long i = 0; i < k; ++i) {
        pon.insert(adun[i]);
    }
    cout << *pon.begin() << "\n";
    for (long long i = k; i < n; ++i) {
        pon.erase(pon.find(adun[i - k]));
        pon.insert(adun[i]);
        cout << *pon.begin() << "\n";
    }
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