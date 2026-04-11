//問題文: https://atcoder.jp/contests/abc453/tasks/abc453_b

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int T, X;
  cin >> T >> X;
  int last_time;
  cin >> last_time;
  cout << 0 << " " << last_time << '\n';
  for(int i = 1; i <= T; i++){
    int time_i;
    cin >> time_i;
    if(abs(time_i - last_time) >= X){
      last_time = time_i;
      cout << i << " " << last_time << '\n';
    }
  }
}