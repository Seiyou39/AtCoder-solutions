//問題文: https://atcoder.jp/contests/abc450/tasks/abc450_d

#include <bits/stdc++.h>
using namespace std;

//ring buffer solution, time complexity O(N log N) due to sorting, space complexity O(N)
//there is a ring and the size is K because  every number is reduced modulo K
//like K = 10 and we have 1, 3, 15, 29, then we have 1, 3, 5, 9 in the ring
//we need to find the maximum gap between two adjacent numbers in the ring
//so that we could put the numbers in the same order in the ring and minimize the range, which is K - max_gap
//like 1, 3, 5, 9, the maximum gap is 4 between 5 and 9
//the size of ring is 10, which means[1*, 2, 3*, 4, 5*, 6, 7, 8, 9*, 0]
//cut the ring between 5 and 9, let the array become more crowded, which is [9*, 0, 1*, 2, 3*, 4, 5*, 6, 7, 8]
//the answer is 10 - 4 = 6



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