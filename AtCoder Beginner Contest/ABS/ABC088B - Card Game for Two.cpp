#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans = 0;
  vector<int> num(N);
  for(int i = 0 ; i < N ; i++){
    cin >> num.at(i);
  }
  sort(num.begin(), num.end(), greater<int>());
  
  for(int i = 0; i < N; i++){
    if(i != 0 && i % 2 == 1){
      ans -= num.at(i);
    }
    else ans += num.at(i);
  }
  
  cout << ans << endl;
    
  
  
}