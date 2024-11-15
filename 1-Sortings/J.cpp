#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> adun(n);
    for (int i = 0; i < n; ++i) {
        cin >> adun[i].first >> adun[i].second;
    }
    sort(adun.begin(), adun.end(), [](pair<int, int> a, pair<int, int> b){
        if (a.second > b.second) {
            return 1;
        } else if (a.second == b.second) {
            if (a.first < b.first) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    });
    for (int i = 0; i < n; ++i) {
        cout << adun[i].first << " " << adun[i].second << "\n";
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