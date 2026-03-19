#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> s(N);
  int ans = 0;
  
  for(int i = 0; i < N ;i++){
    cin >> s.at(i);
  }
  bool check = true;
  
  while(check == true){
    for(int i = 0; i < N ;i++){
      if(s.at(i) % 2 != 0) {
        check = false;
        break;
      }
      else s.at(i) /= 2;
    }
    if(check == true) ans++;
  }
  
  cout << ans << endl;
}