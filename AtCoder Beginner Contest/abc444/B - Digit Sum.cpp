#include<bits/stdc++.h>
using namespace std;

  int sum(int x){
    int s = 0;
    while(x){
      s += x % 10;
      x /= 10;
    }
     return s;
  }

int main(){
  int N;
  int K;
  cin >> N >> K;
  int ans = 0;
  
  for(int i = 0; i <= N; i++){
    if(sum(i) == K) ans++;
  }
  cout << ans << endl;
  
}

