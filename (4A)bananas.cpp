#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;


int main(){
    int t;
    cin >> t;
    vector<int> results(t);
    for (int i = 0; i < t; i++){
        int a, b, c;
        cin >> a >> b >> c;
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(a);
        q.push(b);
        q.push(c);
        
        for(int j = 0; j < 5; j++){
            int min = q.top();
            q.pop();
            q.push(min + 1);
        }
    

        int res = 1;
        for (int k = 0; k < 3; k++){
            res *= q.top();
            q.pop();
        }
        results[i] = res;
    }

    for (int i: results) cout << i << "\n";
    return 0;        
}
