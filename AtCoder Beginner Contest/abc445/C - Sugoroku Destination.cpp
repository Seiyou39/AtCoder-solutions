//問題文: https://atcoder.jp/contests/abc445/tasks/abc445_c
//Use DP, backward from N to 1
//because if A[i] == i, the loop will end in i, otherwise it will jump to A[i] and continue
//and in this problem, it only jumps to right way, so we can use DP to store the answer for each position from N to 1
//Time complexity O(N)

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;
  
  vector<int> A(N + 1);
  for(int i = 1; i <= N; i++){
    cin >> A[i];
  }
  
  vector<int> ans(N + 1);
  for(int i = N; i > 0; i--){
    if(A[i] == i){
      ans[i] = A[i];
    }
    else{
      ans[i] = ans[A[i]];
    }
  }
  
  for(int i = 1; i <= N; i++){
    if(i != N){
      cout << ans[i] << " ";
    }
    else{
      cout << ans[i] << endl;
    }
  }
}