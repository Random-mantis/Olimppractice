#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int BASE = 911382323;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size();

    vector<int> pow1(n + 1), pow2(n + 1);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pow1[i] = (long long)pow1[i - 1] * BASE % MOD1;
        pow2[i] = (long long)pow2[i - 1] * BASE % MOD2;
    }

    vector<int> pref1(n + 1), pref2(n + 1);
    for (int i = 0; i < n; ++i) {
        int v = s[i] - 'a' + 1;
        pref1[i + 1] = ((long long)pref1[i] * BASE + v) % MOD1;
        pref2[i + 1] = ((long long)pref2[i] * BASE + v) % MOD2;
    }

    string rs = s;
    reverse(rs.begin(), rs.end());
    vector<int> rpref1(n + 1), rpref2(n + 1);
    for (int i = 0; i < n; ++i) {
        int v = rs[i] - 'a' + 1;
        rpref1[i + 1] = ((long long)rpref1[i] * BASE + v) % MOD1;
        rpref2[i + 1] = ((long long)rpref2[i] * BASE + v) % MOD2;
    }

    auto get_hash = [&](const vector<int>& pref, int l, int len, int mod) {
        return (pref[l + len] - (long long)pref[l] * pow1[len] % mod + mod) % mod;
    };

    for (int L = n; L >= 1; --L) {
        int h1 = pref1[L];
        int h2 = pref2[L];
        int rh1 = (rpref1[n] - (long long)rpref1[n - L] * pow1[L] % MOD1 + MOD1) % MOD1;
        int rh2 = (rpref2[n] - (long long)rpref2[n - L] * pow2[L] % MOD2 + MOD2) % MOD2;
        if (h1 == rh1 && h2 == rh2) {
            cout << L << '\n';
            return 0;
        }
    }

    return 0;
}