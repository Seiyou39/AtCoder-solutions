//問題文: https://atcoder.jp/contests/abc450/tasks/abc450_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    vector<long long> r(N);
    for (int i = 0; i < N; i++) {
        long long A;
        cin >> A;
        r[i] = A % K;
    }

    sort(r.begin(), r.end());

    long long max_gap = 0;

    for (int i = 0; i < N - 1; i++) {
        max_gap = max(max_gap, r[i + 1] - r[i]);
    }
    max_gap = max(max_gap, r[0] + K - r[N - 1]);

    cout << K - max_gap << endl;
}