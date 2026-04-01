//問題文: https://atcoder.jp/contests/abc451/tasks/abc451_a

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string S;
  cin >> S;
  
  if(S.size() % 5 != 0){
    cout << "No" << '\n';
  }
  else{
    cout << "Yes" << '\n';
  }
}