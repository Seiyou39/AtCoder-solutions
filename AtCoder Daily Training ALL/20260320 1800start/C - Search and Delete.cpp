//問題文: https://atcoder.jp/contests/adt_all_20260320_2/tasks/abc417_b
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
    int key;
    cin >> key;
    A[key]++;
  }
  for(int i =0; i < M; i++){
    int key;
    cin >> key;
    B[key]++;
  }
  
  for(auto& [key, val] : B){
    if(A[key] <= val) A[key] = 0;
    else A[key] -= val;
  }
  
  for(auto& [key, val] : A){
    for(int i = val; i > 0; i--){
      cout << key << " ";
    }
  }
  cout << endl;
}