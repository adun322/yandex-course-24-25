#include <bits/stdc++.h>
using namespace std;


void solve() {
    string a;
    vector<string> pon;
    while (cin >> a) {
        pon.push_back(a);
    }
    sort(pon.begin(), pon.end(), [](string a, string b){
        if (a + b > b + a) {
            return 1;
        } else {
            return 0;
        }
    });
    for (auto i : pon) {
        cout << i;
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