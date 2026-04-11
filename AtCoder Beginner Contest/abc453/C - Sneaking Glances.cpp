//問題文: https://atcoder.jp/contests/abc453/tasks/abc453_c


//bit brute force

/* 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> step(N);
    for (int i = 0; i < N; i++) cin >> step[i];

    int ans = 0;
    for (int tmp = 0; tmp < (1 << N); tmp++) {
        bitset<20> s(tmp);
        long long pos = 0.5;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            long long nxt = pos + (s[i] ? step[i] : -step[i]);
            if ((pos > 0) != (nxt > 0)) cnt++;
            pos = nxt;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
*/
//recursion
//hint from knapsack problem
#include<bits/stdc++.h>
using namespace std;

int N;
vector<long long> step;
int ans = 0;

void recursion(int i, long long pos, int cnt){
  if(i == N){
    ans = max(ans, cnt);
    return;
  }
  //go right
  long long nxt1 = pos + step[i];
  int add1 = ((pos > 0) != (nxt1 > 0)) ? 1 : 0;//passed 0 ? 1 : 0
  recursion(i + 1, nxt1, cnt + add1);

  //go left
  long long nxt2 = pos - step[i];
  int add2 = ((pos > 0) != (nxt2 > 0)) ? 1 : 0;//passed 0 ? 1 : 0
  recursion(i + 1, nxt2, cnt + add2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for(int i = 0; i < N; i++){
    long long tmp;
    cin >> tmp;
    step.push_back(tmp);
  }
  recursion(0, 0.5, 0);
  cout << ans << '\n';
}
