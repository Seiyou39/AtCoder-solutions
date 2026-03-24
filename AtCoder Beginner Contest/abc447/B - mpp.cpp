//問題文: https://atcoder.jp/contests/abc447/tasks/abc447_b

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  cin >> S;
  
  map<char, int> mp;
  for(char c : S){
    mp[c]++;
  }
  
  int mx = 0;
  for(auto& [key, val] : mp){
    mx = max(mx, val);
  }
  
  for(char c : S){
    if(mp[c] != mx){
      cout << c;
    }
  }
  cout << '\n';
  
}