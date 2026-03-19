#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  vector<string> words = {"dream", "dreamer", "erase", "eraser"};
  
  vector<bool> dp(S.size() + 1);
  dp[0] = true;
  
  for(int i = 1; i <= S.size(); i++){
    for(string x : words){
      if(i >= x.size() &&
        S.substr(i - x.size(), x.size()) == x &&
        dp[i - x.size()] == true){
          dp[i] = true;
        }
    }
  }
  
  if(dp[S.size()] == true){
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
}