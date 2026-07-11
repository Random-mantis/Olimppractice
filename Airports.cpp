#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }

    int total = 1 << n;
    const int INF = 1e9;
    vector<int> dp(total * n, INF);

    dp[n] = 0;

    for (int mask = 0; mask < total; ++mask) {
        for (int v = 0; v < n; ++v) {
            int cur = dp[mask * n + v];
            if (cur == INF) continue;

            for (int u = 0; u < n; ++u) {
                if (mask & (1 << u)) continue;
                int newMask = mask | (1 << u);
                int &ref = dp[newMask * n + u];
                int val = cur + c[v][u];
                if (val < ref) ref = val;
            }
        }
    }

    int fullMask = total - 1;
    int ans = INF;
    for (int v = 0; v < n; ++v) {
        ans = min(ans, dp[fullMask * n + v] + c[v][0]);
    }

    cout << ans << '\n';
    return 0;
}