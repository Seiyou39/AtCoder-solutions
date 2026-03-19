//在一个盒子里有许多长为L的棍子，如果没出现断裂，那么L必定是盒子里的最大值且所有值都相同。
//如果仅一部分棍子出现断裂，那么L必定是盒子里最小值和次大值之和且等于最大值。
//如果所有棍子均断裂，那么L必定是最小值和最大值之和。
//综上所述，L有三种可能，分别进行验证即可。
//验证时需要注意奇偶性问题，若L为最小值和最大值之和，则需要保证剩余棍子数为偶数。
//时间复杂度O(NlogN)
//还需注意，当遇见匹配的情况时，答案可能有多个，需要去重输出。
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<uint64_t> ans;
  vector<uint64_t> A;
  for(int i = 0; i < N; i++){
    int n;
    cin >> n;
    A.push_back(n);
  }
  sort(A.begin(), A.end());
  uint64_t amax = A.back();
  uint64_t amin = A.front();
  
  if(N % 2 == 0){
    bool push = true;
    for(int i = 0, j = (int)A.size() - 1; i < j; i++, j--){
      if(A[i] + A[j] != (amin + amax))push = false;
    }
    if(push)ans.push_back(amin + amax);
  }
  
  while(!A.empty() && A.back() == amax){
    A.pop_back();
  }
  if(A.empty()){
    ans.push_back(amax);
  }
  else if(amin + A.back() == amax){
    int l = 0, r = A.size() - 1;
    bool ok = true;
    while(l < r){
      if(A[l] + A[r] != amax){
        ok = false;
        break;
      }
      l++;r--;
    }
    if(l == r) ok = false;
    if(ok)ans.push_back(amax);
  }
  
  sort(ans.begin(), ans.end());
  
  for(int i = 0; i < ans.size(); i++){
    if(i == ans.size() - 1){
      cout << ans[i] << endl;
    }
    else cout << ans[i] << " ";
  }
}