//問題文: https://atcoder.jp/contests/abc443/tasks/abc443_c
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, T;
  cin >> N >> T;
  if(N == 0){
    cout << T << endl;
  }
  else{
    vector<int> times(N);
    int chokutter; 
    for(int i = 0; i < N; i++){
      cin >> times[i];
    }
    chokutter = times[0];
    int next = times[0] + 100;
    for(int i = 1; i < N; i++){
      if(next <= times[i]){
        chokutter += times[i] - next;
        next = times[i] + 100;
      }
    }
    if(next < T){
      chokutter += T - next;
    }
    cout << chokutter <<endl;
  }
  
  return 0;
  
}