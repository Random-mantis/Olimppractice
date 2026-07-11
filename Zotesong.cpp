#include <iostream>
#include <vector>
using namespace std;

//rwhebkwoi9uyghdfjipoqew8ruygfhdeiqw98urygrhewi90uryghrfejwi9urfh

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    long long sum = 1;
    const int MOD = 1000000007;
    for (int i = 1; i <= n; ++i) {
        if (i - k - 1 >= 0) {
            sum = (sum - dp[i - k - 1] + MOD) % MOD;
        }
        dp[i] = sum;
        sum = (sum + dp[i]) % MOD;
    }
    cout << dp[n] << '\n';
    return 0;
}