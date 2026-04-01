//問題文: https://atcoder.jp/contests/abc451/tasks/abc451_b

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N, M;
  cin >> N >> M;
  
  map<int, int> A;
  map<int, int> B;
  for(int i = 0; i < N; i++){
    int a, b;
    cin >> a >> b;
    A[a]++;
    B[b]++;
  }
  for(int i = 1; i <= M; i++){
    cout << B[i] - A[i] << '\n';
  }
  
}