//問題文: https://atcoder.jp/contests/abc450/tasks/abc450_a
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;
  
  for(int i = N; i > 0; i--){
    if(i != 1){
      cout << i << ',';
    }
    else cout << i << endl;
  }
  cout << endl;
}