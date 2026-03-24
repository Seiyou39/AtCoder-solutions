//問題文: https://atcoder.jp/contests/abc447/tasks/abc447_a

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  
  if(2 * M - 1 <= N)cout << "Yes" << '\n';
  else cout << "No" << '\n';
}