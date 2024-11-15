#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    long long q;
    cin >> q;
    map<string, long long> sklad;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            string name; long long n;
            cin >> name;
            cin >> n;
            vector<pair<string, long long>> pon(n);
            long long k; string s;
            long long f = 1;
            for (int i = 0; i < n; ++i) {
                cin >> k >> s;
                pon.push_back({s, k});
                if (sklad[s] < k) {
                    f = 0;
                }
            }
            if (f) {
                cout << "Milkshake " << name << " is ready\n";
                for (auto i : pon) {
                    sklad[i.first] -= i.second;
                }
            } else {
                cout << ":(" << "\n";
                pon.clear();
            }
        } else {
            long long k; string s;
            cin >> k >> s;
            sklad[s] += k;
            cout << s << ": " << sklad[s] << "\n";
        }
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