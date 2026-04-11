//問題文: https://atcoder.jp/contests/abc453/tasks/abc453_a
// I hate this problem.
//I just lost 20 minutes to solve this problem because I didn't read the problem statement carefully.
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  string S;
  cin >> N >> S;
  int sentinel = 0;
  for(char x : S){
    if(x == 'o' && sentinel == 0){
      continue;
    }
    else{
     sentinel = 1;
     cout << x;
    }
  }
  cout << '\n';
}