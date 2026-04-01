//問題文: https://atcoder.jp/contests/abc451/tasks/abc451_c

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int Q;
  cin >> Q;
  int ans = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0; i < Q; i++){
    int a;
    long long h;
    int cnt = 0;
    cin >> a >> h;
    
    if(a == 1){
      ans++;
      pq.push(h);
    }
    else{
      while (!pq.empty() && pq.top() <= h) {
        pq.pop();
        cnt++;
      }
      ans -= cnt;
    }
    cout << ans << '\n';
  }
  
}