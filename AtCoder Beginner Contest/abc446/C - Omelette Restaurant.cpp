//問題文: https://atcoder.jp/contests/abc446/tasks/abc446_c
//FIFO queue  data strcture qusiton.
//Fist I thought it is a [D] window like [day1, day2, day3, ... , dayD]
//but it is too noisy to shift
//so it is easier to use a queue.
//
#include<bits/stdc++.h>
using namespace std;



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int T;
  cin >> T;
  
  for(int i = 0; i < T; i++){
    int N, D;
    cin >> N >> D;
    
    deque<pair<int, int>> dq;
    vector<int> A(N + 1);
    vector<int> B(N + 1);
    for(int i = 1; i < N + 1; i++){
      cin >> A[i];
    }
    for(int i = 1; i < N + 1; i++){
      cin >> B[i];
    }
    
    for(int i = 1; i < N + 1; i++){
      
      dq.push_back({i, A[i]});
      int need = B[i];
      
      
      while(need != 0){
        if(need >= dq.front().second){
          need -= dq.front().second;
          dq.pop_front();
        }
        else{
          dq.front().second -= need;
          need = 0;
        }
      }
      
      
       if( !dq.empty() && dq.front().first + D == i){
          dq.pop_front();
        }
        
    }
    
    int ans = 0;
        for(auto&[key, val] : dq){
          ans += val;
        }
        
        cout << ans << '\n';
  }
}