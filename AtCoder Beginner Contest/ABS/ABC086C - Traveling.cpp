#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int t = 0, x = 0, y = 0;
  bool ans = true;
  for(int i = 0; i < N ; i++){
    int vt, xt, yt;
    cin >> vt >> xt >> yt;
   int distance = abs(xt -x) + abs(yt - y);
   int time = vt-t;
   if((distance > time) || ((time - distance) % 2 != 0)){
     ans = false;
     break;
   }
     t = vt;
     x = xt;
     y = yt;
  }
  if(ans){
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
}