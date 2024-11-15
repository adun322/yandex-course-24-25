#include <bits/stdc++.h>
using namespace std;


void solve() {
        string s;
    cin >> s;
    map<int, int> pon;
    int x;
    vector<pair<int, int>> adun;
    for (int i = 0; i < 26; ++i) {
        cin >> x;
        pon['a' + i] = x;
        adun.push_back({'a' + i, x});
    }

    map<int, int> c;
    vector<char> l;
    for (int i = 0; i < s.size(); ++i) {
        c[s[i]]++;
        if (c[s[i]] == 2) {
            l.push_back(s[i]);
        }
    }
    sort(l.begin(), l.end(), [&pon](int a, int b){
        if (pon[a] > pon[b]) {
            return true;
        } else {
            return false;
        }
    });
    deque<char> a1, a2;
    map<int, int> p;
    for (int i = 0; i < l.size(); ++i) {
        cout << l[i];
        p[l[i]] = 2;
        a2.push_front(l[i]);
    }
    for (auto i : s) {
        if (p[i] > 0) {
            p[i]--;
        } else {
            cout << i;
        }
    }
    for (auto i : a2) {
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