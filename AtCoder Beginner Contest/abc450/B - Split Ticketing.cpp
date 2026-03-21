//問題文: https://atcoder.jp/contests/abc450/tasks/abc450_b

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;
  
  vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
  
  for(int i = 1; i < N + 1; i++){
    for(int j = i + 1; j < N + 1; j++){
      cin >> arr[i][j];
    }
  }
  for(int a = 1; a <= N - 2; a++){
    for(int b = a + 1; b <= N - 1; b++){
      for(int c = b + 1; c <= N; c++){
        if(arr[a][c] > arr[a][b] + arr[b][c]){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}