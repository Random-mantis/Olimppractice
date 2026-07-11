#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r;
    cin >> l >> r;

    vector<int> dp(r + 1, 0);
    dp[1] = 1;

    for (int i = 1; i <= r; ++i) {
        if (dp[i] == 0) continue;
        int val = dp[i];
        for (int j = i + i; j <= r; j += i) {
            dp[j] += val;
            if (dp[j] >= MOD) dp[j] -= MOD;
        }
    }

    int ans = 0;
    for (int i = l; i <= r; ++i) {
        ans += dp[i];
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans << '\n';
    return 0;
}