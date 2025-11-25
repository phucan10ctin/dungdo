// Author: Nguyễn Phúc An
// Time: 20:10 PM 25/11/2025 (GMT+7)
// Location: Binh Thanh, Ho Chi Minh City, Vietnam
// Link problem: https://oj.clue.edu.vn/problem/kh_ts10_24_bai4
#include <iostream>
#include <vector>
using namespace std;
using ll = unsigned long long;
vector<ll> prefix;
const ll INF = 1e18;
int n;
void xuli() {
    ll i = 2;
    prefix.push_back(-1);
    prefix.push_back(1);
    while(true) {
        if(prefix[prefix.size() - 1] + i * i > INF) break;
        prefix.push_back(prefix[prefix.size()-1] + i * i);
        i++;
    }
    n = prefix.size() - 1;
}
void AC() {
    ll x; cin >> x;
    ll l = 1, r = n, ans = -1;
    ll m;
    while(l <= r) {
        m = (l + r)/2;
        if(prefix[m] <= x) {
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    cout << ans << ' ';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    xuli();
    int q; cin >> q;
    while(q--) AC();
    return 0;
}
