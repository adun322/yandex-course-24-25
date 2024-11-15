#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    int n;
    cin >> n;
    deque<int> adun(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> adun[i];
    }
    deque<int> q;
    vector<string> res;
    for (int i = 1; i <= n; ++i) {
        if (q.front() == i) {
            res.push_back("2 1");
            q.pop_front();
            continue;
        } else {
            for (int j = 0; j < q.size(); ++j) {
                if (q[j] == i) {
                    cout << 0;
                    return;
                }
            }
            int x = adun.size();
            for (int j = 0; j < x; ++j) {
                if (adun.front() == i) {
                    res.push_back("1 " + to_string(j + 1));
                    adun.pop_front();
                    res.push_back("2 1");
                    break;
                }
                q.push_front(adun.front());
                adun.pop_front();
            }
        }
    }
    cout << res.size() << "\n";
    for (auto i : res) {
        cout << i << "\n";
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