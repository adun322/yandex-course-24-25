#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 2;
int MOD = 998244353;

struct node {
    int sum_v = 0;
    int sum_h = 0;

    node operator+(node &other) {
        return {min(sum_v, other.sum_v), min(sum_h, other.sum_h)};
    }
};

node tree[4 * MAXN];

void update_v(int v, int lb, int rb, int i, int x) {
    if (lb + 1 == rb) {
        tree[v].sum_v += x;
        return;
    }
    int m = (lb + rb) / 2;
    if (i >= m) {
        update_v(2 * v + 2, m, rb, i, x);
    } else {
        update_v(2 * v + 1, lb, m, i, x);
    }
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

void update_h(int v, int lb, int rb, int i, int x) {
    if (lb + 1 == rb) {
        tree[v].sum_h += x;
        return;
    }
    int m = (lb + rb) / 2;
    if (i >= m) {
        update_h(2 * v + 2, m, rb, i, x);
    } else {
        update_h(2 * v + 1, lb, m, i, x);
    }
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

int get_v(int v, int lb, int rb, int lq, int rq) {
    if (lq >= rb || lb >= rq) {
        return MAXN;
    }
    if (lq <= lb && rq >= rb) {
        return tree[v].sum_v;
    }
    int m = (lb + rb) / 2;
    return min(get_v(2 * v + 1, lb, m, lq, rq), get_v(2 * v + 2, m, rb, lq, rq));
}

int get_h(int v, int lb, int rb, int lq, int rq) {
    if (lq >= rb || lb >= rq) {
        return MAXN;
    }
    if (lq <= lb && rq >= rb) {
        return tree[v].sum_h;
    }
    int m = (lb + rb) / 2;
    return min(get_h(2 * v + 1, lb, m, lq, rq), get_h(2 * v + 2, m, rb, lq, rq));
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            update_v(0, 0, n, x - 1, 1);
            update_h(0, 0, n, y - 1, 1);
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            update_v(0, 0, n, x - 1, -1);
            update_h(0, 0, n, y - 1, -1);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int ans_v = get_v(0, 0, n, x1 - 1, x2);
            int ans_h = get_h(0, 0, n, y1 - 1, y2);
            if (ans_v || ans_h) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
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