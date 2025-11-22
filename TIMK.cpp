#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
using ll = long long;
int n,m;
ll legendre(int x) {
    ll cnt = 0;
    for(int i = x; i <= n; i*=x) {
        cnt+=(n/i);
    }
    return cnt;
}
void AC() {
    cin >> n >> m;
    ll res = LLONG_MAX;
    for(int i = 2; i * i <= m; i++) {
        if(m % i == 0) {
            ll cnt = 0;
            while(m % i == 0) {
                cnt++;
                m/=i;
            }
            ll num = 1;
            for(int k = 1; k <= cnt; k++) {
                num*=i;
            }
            res = min(legendre(num), res);
        }
    }
    if(m > 1) {
        res = min(legendre(m), res);
    }
    cout << res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("TIMK.INP", "r", stdin);
    freopen("TIMK.OUT", "w", stdout);
    AC();
    return 0;
}
