//問題文: https://atcoder.jp/contests/adt_all_20260320_2/tasks/abc280_a
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int H, W;
  cin >> H >> W;
  int ans = 0;
  
  for(int i = 0; i < H; i++){
    vector<char> in(W);
    for(int j = 0; j < W; j++){
      cin >> in[j];
      if(in[j] == '#'){
        ans++;
      }
    }
  }
  cout << ans << endl;
}