#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    long long n, m, k;
    cin >> n >> m >> k;
    map<long long, set<long long>> adun1, adun2;
    while (k--) {
        string a;
        cin >> a;
        long long e, s;
        if (a == "ADD") {
            cin >> e >> s;
            adun1[s].insert(e);
            adun2[e].insert(s);
        } else if (a == "DELETE") {
            cin >> e >> s;
            adun1[s].erase(e);
            adun2[e].erase(s);
        } else if (a == "CLEAR") {
            cin >> s;
            for (auto i : adun1[s]) {
                adun2[i].erase(s);
            }
            adun1[s].clear();
        } else if (a == "LISTSET") {
            cin >> s;
            if (adun1[s].empty()) {
                cout << -1 << "\n";
                continue;
            }
            for (auto i : adun1[s]) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            cin >> e;
            if (adun2[e].empty()) {
                cout << -1 << "\n";
                continue;
            }
            for (auto i : adun2[e]) {
                cout << i << " ";
            }

            cout << "\n";
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