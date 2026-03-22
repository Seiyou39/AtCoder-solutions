//問題文: https://atcoder.jp/contests/abc446/tasks/abc446_a
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string S;
  cin >> S;
  
  for(char& x : S){
    x = tolower(x);
  }
  cout << "Of" << S << '\n';
}