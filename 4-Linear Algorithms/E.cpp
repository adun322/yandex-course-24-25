//
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n1, n2, n3, n4, p;
    vector<long long> a1, a2, a3, a4;
    cin >> n1;
    for (long long i = 0; i < n1; ++i) {
        cin >> p;
        a1.push_back(p);
    }
    cin >> n2;
    for (long long i = 0; i < n2; ++i) {
        cin >> p;
        a2.push_back(p);
    }
    cin >> n3;
    for (long long i = 0; i < n3; ++i) {
        cin >> p;
        a3.push_back(p);
    }
    cin >> n4;
    for (long long i = 0; i < n4; ++i) {
        cin >> p;
        a4.push_back(p);
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(a3.begin(), a3.end());
    sort(a4.begin(), a4.end());
    long long i = 0, j = 0, l = 0, r = 0, minn, maxx, k,
            diff = max({a1[0], a2[0], a3[0], a4[0]}) -
                   min({a1[0], a2[0], a3[0], a4[0]}), r1 = a1[0], r2 = a2[0], r3 = a3[0], r4 = a4[0];
    while (i < n1 && j < n2 && l < n3 && r < n4) {
        maxx = max({a1[i], a2[j], a3[l], a4[r]});
        minn = min({a1[i], a2[j], a3[l], a4[r]});
        k = maxx - minn;
        if (k < diff) {
            diff = k;
            r1 = a1[i];
            r2 = a2[j];
            r3 = a3[l];
            r4 = a4[r];
        }
        if (k == 0) {
            break;
        }
        if (a1[i] == minn && i < a1.size()) {
            ++i;
        }
        if (a2[j] == minn && j < a2.size()) {
            ++j;
        }
        if (a3[l] == minn && l < a3.size()) {
            ++l;
        }
        if (a4[r] == minn && r < a4.size()) {
            ++r;
        }
    }
    cout << r1 << " " << r2 << " " << r3 << " " << r4;
}
//*/