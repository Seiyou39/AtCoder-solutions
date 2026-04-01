//問題文: https://atcoder.jp/contests/abc451/tasks/abc451_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> blocks;
    for (long long p = 1; p <= 1000000000LL; p *= 2) {
        blocks.push_back(p);
    }

    vector<long long> pow10(11, 1);
    for (int i = 1; i <= 10; i++) {
        pow10[i] = pow10[i - 1] * 10;
    }

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    unordered_set<long long> visited;

    for (auto b : blocks) {
        visited.insert(b);
        pq.push(b);
    }

    int count = 0;
    while (!pq.empty()) {
        long long x = pq.top();
        pq.pop();
        count++;
        if (count == N) {
            cout << x << endl;
            return 0;
        }
        for (auto b : blocks) {
            int digits = to_string(b).size();
            long long new_val = x * pow10[digits] + b;
            if (new_val <= 1000000000LL && visited.count(new_val) == 0) {
                visited.insert(new_val);
                pq.push(new_val);
            }
        }
    }

return 0;

}