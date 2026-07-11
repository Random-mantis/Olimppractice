#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> result;
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        if (2 * a <= b) result.push_back(n * a);
        else{
            if (n % 2 == 0) result.push_back(b * (n / 2));
            else result.push_back(b * ((n - 1) / 2) + a);
        }
    }
    for (int i: result) cout << i<< '\n';
    return 0;
}