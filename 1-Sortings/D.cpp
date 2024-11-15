#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += 10000;
    }
    vector<int> c(20010, 0);
    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }

    int k = 0;
    for (int i = 0; i < 20003; i++) {
        while (c[i] != 0) {
            a[k] = i;
            k++;
            c[i]--;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] - 10000 << " ";
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