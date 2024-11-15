#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    char c;
    lld n, i, sum;
    deque<lld> firstH, secondH;
    cin >> n;
    while (n--) {
        cin >> c;
        switch (c) {
            case '+': {
                cin >> i;
                secondH.push_back(i);
                break;
            }
            case '*': {
                cin >> i;
                if (firstH.size() == secondH.size()) {
                    firstH.push_back(i);
                } else {
                    secondH.push_front(i);
                }
                break;
            }
            case '-': {
                cout << (int)firstH.front() << "\n";
                firstH.pop_front();
                break;
            }
        }
        // Balance:
        if (firstH.size() < secondH.size()) {
            firstH.push_back(secondH.front());
            secondH.pop_front();
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