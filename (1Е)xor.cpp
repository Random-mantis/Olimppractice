#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int child[2];
    Node() {
        child[0] = child[1] = -1;
    }
};

vector<Node> trie;

void insert(int x) {
    int cur = 0;
    for (int bit = 30; bit >= 0; --bit) {
        int b = (x >> bit) & 1;
        if (trie[cur].child[b] == -1) {
            trie[cur].child[b] = trie.size();
            trie.emplace_back();
        }
        cur = trie[cur].child[b];
    }
}

int maxXor(int x) {
    int cur = 0, res = 0;
    for (int bit = 30; bit >= 0; --bit) {
        int b = (x >> bit) & 1;
        if (trie[cur].child[1 - b] != -1) {
            res |= (1 << bit);
            cur = trie[cur].child[1 - b];
        } else {
            cur = trie[cur].child[b];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> result;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        trie.clear();
        trie.emplace_back();

        for (int x : a) insert(x);

        int ans = 0;
        for (int x : a) {
            ans = max(ans, maxXor(x));
        }
        result.push_back(ans);
    }
    for(auto i: result) cout << i << '\n';
}
