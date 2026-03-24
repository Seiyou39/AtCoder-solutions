//問題文: https://atcoder.jp/contests/abc447/tasks/abc447_c


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<string, vector<int>> parse(const string& s) {
    string core;
    vector<int> gaps;

    int i = 0, n = s.size();

    while (true) {
        int cnt = 0;
        //[AA]B[AAAA]CD[AA]EF[AA]G -> core = "BCD" gaps = [2, 4, 2, 2] Smart!
        while (i < n && s[i] == 'A') {
            cnt++;
            i++;
        }
        gaps.push_back(cnt);

        if (i == n) break;

        core += s[i];
        i++;
    }

    return {core, gaps};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    auto [coreS, gapsS] = parse(S);
    auto [coreT, gapsT] = parse(T);

    if (coreS != coreT) {
        cout << -1 << '\n';
        return 0;
    }

    ll ans = 0;
    for (int i = 0; i < gapsS.size(); i++) {
        ans += abs(gapsS[i] - gapsT[i]);
    }

    cout << ans << '\n';
}








/*improve solution 1, do not need to reset positionS everytime, it is too slow.
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string S, T;
  cin >> S >> T;
  
  vector<int> positionS;
  vector<int> positionT;
  int index = 0;
  
  //record the position of non-A characters in T and S
  for(char c : T){
    if(c != 'A'){
      positionT.push_back(index);
    }
    index++;
  }
  index = 0;
  for(char c : S){
    if(c != 'A'){
      positionS.push_back(index);
    }
    index++;
  }
  
  //check board size and non-A characters
  if(positionS.size() != positionT.size()){
    cout << -1 << '\n';
    return 0;
  }
  
 if(positionS.empty() && positionT.empty()){
    cout << abs((int)S.size() - (int)T.size()) << '\n';
    return 0;
  }
  
  //[AA]B[AAAA]CD[AA]EF[AA]G
  //calculate A's amount of each block to compare with T's amount of each block
  //the diff of them is the steps 
  int ans = 0;
  for(int i = 0; i < (int)positionS.size() - 1; i++){
    if(S[positionS[i]] != T[positionT[i]]){
        cout << -1 << '\n';
        return 0;
    }
    int j = i + 1;
    int diff = abs((positionT[j] - positionT[i]) - (positionS[j] - positionS[i]));
    ans += diff;
  }

  //because we only compare the blocks between non-A characters
  //so plus the diff of head and tail of the string
  int head = abs(positionS[0] - positionT[0]);
  int S_tail = S.size() - positionS.back() - 1;
  int T_tail = T.size() - positionT.back() - 1;
  
  cout << ans + abs(S_tail - T_tail) + head << '\n';
  
}
*/





/*solution 1
//do not need to reset positionS everytime, it is too slow. 
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S, T;
  cin >> S >> T;
  
  vector<int> positionS;
  vector<int> positionT;
  int index = 0;
  
  //record the position of non-A characters in T and S
  for(char c : T){
    if(c != 'A'){
      positionT.push_back(index);
    }
    index++;
  }
  index = 0;
  for(char c : S){
    if(c != 'A'){
      positionS.push_back(index);
    }
    index++;
  }
  
  //check board size and non-A characters
  if(positionS.size() != positionT.size()){
    cout << -1 << '\n';
    return 0;
  }
  if(positionS.empty() && positionT.empty()){
    cout << abs((int)S.size() - (int)T.size()) << '\n';
    return 0;
  }
  
  for(int i = 0; i < (int)positionS.size(); i++){
    if(S[positionS[i]] != T[positionT[i]]){
        cout << -1 << '\n';
        return 0;
    }
  }

  //count A from last non-A character to the end of the string
  int S1 =S.size() - positionS.back() - 1;
  int T1 =T.size() - positionT.back() - 1;
  

  //calculate the steps needed to move non-A characters in positionS to the same position as in T
  int step = 0;
  for(int i = 0; i < (int)positionS.size(); i++){
    if(positionS[i] != positionT[i]){
      int move = positionS[i] - positionT[i];
      step += abs(move);
      for(int j = i; j < (int)positionS.size(); j++){
        positionS[j] -= move;
      }
    }
    
  }
    
    cout << step + abs(S1 - T1) << '\n';

}

*/