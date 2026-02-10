#include<bits/stdc++.h>
using namespace std;

int main(){
  int ans;
  string s;
  cin >> s;
  for(char x : s){
    if(x =='1')ans++;
  }
  cout << ans << endl;
}