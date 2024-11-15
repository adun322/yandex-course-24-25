#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> lm(n);
    vector<long long> rm(n);
    for (long long i = 0; i < n; ++i) {
        lm[i] = rm[i] = i;
    }
    vector<pair<long long, long long> > st;
    for (long long i = 0; i < n; ++i) {
        while (st.size() && st.back().first >= a[i]) {
            st.pop_back();
        }

        if (st.size())
            lm[i] = st.back().second;
        else
            lm[i] = -1;

        st.push_back({a[i], i});
    }
    st.clear();
    for (long long i = n - 1; i >= 0; --i) {
        while (st.size() && st.back().first >= a[i]) {
            st.pop_back();
        }
        if (st.size())
            rm[i] = st.back().second;
        else
            rm[i] = n;
        st.push_back({a[i], i});
    }
    long long answer = 0;
    for (long long i = 0; i < n; ++i) {
        answer = max(answer, (rm[i] - lm[i] - 1) * a[i]);
    }
    cout << answer;
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