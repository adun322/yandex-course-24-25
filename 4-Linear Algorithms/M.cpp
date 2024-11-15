#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    int n; cin >> n;
    vector<int> nums(n), adun, res;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    res.resize(nums.size(), -1);
    for (int i = 0; i < nums.size(); ++i) {
        while (!adun.empty() && nums[adun.back()] > nums[i]) {
            res[adun.back()] = i;
            adun.pop_back();
        }
        adun.push_back(i);
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
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