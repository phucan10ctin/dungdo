// Author: Nguyễn Phúc An
// Time: 17:35 PM
// Location: Binh Thanh, Ho Chi Minh City, Vietnam
// note: it takes me a whole day at school (from the first break time in the morning) and 30 minutes at home :v
// A good problem
// https://oj.clue.edu.vn/problem/qn_ts10_24_list
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll mark[26];
int n;
bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
    return a.second < b.second;
}
void AC() {
    string s; cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++) {
        if(mark[s[i] - 'a'] == 0) mark[s[i]-'a'] = i + 1;
    }
    vector<pair<ll,ll>> data;
    for(int i = 0; i < 26; i++) {
        if(mark[i] != 0) data.push_back({i,mark[i]});
    }
    sort(data.begin(), data.end(), cmp);
    pair<ll,ll> toswap = {-1,-1};
    for(auto it : data) {
        ll valnow = it.first;
        ll marknow = it.second;
        bool flag = false;
        for(int j = 0; j < valnow; j++) {
            if(mark[j] != 0 && mark[j] > marknow) {
                toswap = {valnow, j};
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(toswap.first == -1 && toswap.second == -1) cout << s;
    else {
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a' + toswap.first) s[i] = 'a' + toswap.second;
            else if(s[i] == 'a' + toswap.second) s[i] = 'a' + toswap.first;
        }
        cout << s;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    AC();
    return 0;
}
