//問題文: https://atcoder.jp/contests/abc446/tasks/abc446_b
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N, M;
  cin >> N >> M;
  
  vector<bool> used(M + 1, false);
  for(int i = 0; i < N; i++){
    int L;
    cin >> L;
    int ans = 0;
    
    for(int j = 0; j < L; j++){
      int tmp;
      cin >> tmp;
      
      if(!used[tmp] && ans == 0){
        ans = tmp;
        used[tmp] = true;
        
      }
    }
    
    cout << ans << '\n';
    
    
  }
}



/* too slow O(NM)
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N, M;
  cin >> N >> M;
  vector<int> pool(M + 1);
  iota(pool.begin(), pool.end(), 0);
  
  for(int i = 0; i < N; i++){
    int L;
    cin >> L;
    vector<int> X(L);
    for(int j = 0; j < L; j++){
      cin >> X[j];
    }
    bool zero = true;
    for(int j = 0; j < L; j++){
      if(find(pool.begin(), pool.end(), X[j]) != pool.end()){
      cout << X[j] << '\n';
      pool[X[j]] = -1;
      zero = false;
      break;
      }
    }
    if(zero){
      cout << 0 << '\n';
    }
    
  }
}
*/