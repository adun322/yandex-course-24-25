#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

unsigned int a, b;
unsigned int cur = 0;

unsigned int nextRand() {
    cur = cur * a + b;

    return cur >> 8;
}

unsigned mas[1 << 24];

void solve() {
    int m, q;
    cin >> m >> q;

    cin >> a >> b;

    for (int i = 0; i < m; ++i) {
        unsigned add = nextRand();
        unsigned l = nextRand();
        unsigned r = nextRand();

        if (l > r)
            swap(l, r);

        mas[l] += add;
        if (r != (1 << 24) - 1) {
            mas[r + 1] -= add;
        }
    }

    for (int i = 1; i < (1 << 24); ++i) {
        mas[i] += mas[i - 1];
    }

    for (int i = 1; i < (1 << 24); ++i) {
        mas[i] += mas[i - 1];
    }

    unsigned ans = 0;

    for (int i = 0; i < q; ++i) {
        unsigned l = nextRand();
        unsigned r = nextRand();

        if (l > r)
            swap(l, r);

        unsigned answer = mas[r];
        if (l != 0) {
            answer -= mas[l - 1];
        }

        ans += answer;
    }

    cout << ans;

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