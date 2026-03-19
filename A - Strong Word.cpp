//問題文: https://atcoder.jp/contests/abc445/tasks/abc445_a

#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  
  cin >> S;
  
  if(S[0] == S.back()){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}