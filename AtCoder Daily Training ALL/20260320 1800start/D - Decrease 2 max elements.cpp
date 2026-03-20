//問題文: https://atcoder.jp/contests/adt_all_20260320_2/tasks/abc368_b
//I realized that if the biggest number is greater than the sum of the rest
//then the answer is the sum of the rest because the sum of the rest can only decrease itself
//otherwise, the answer is the sum / 2 because that is the maximum times we can decrease
//so minimum of these two is the anser

//最大数大于其他数之和，够减，把其他数总和减完的时候就剩他自己了
//最大数小于等于其他数之和，不够减，所以其他数每次都能和最大数一起减，直到所有数都变成0了，所以最多能减sum/2次，留下的一定是最大数减出来的

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;
  
  vector<int> num(N);
  for(int i = 0; i < N; i++){
    cin >> num[i];
  }
  
  int mx = *max_element(num.begin(), num.end());
  int sum = accumulate(num.begin(), num.end(), 0);
  
  int ans = min((sum - mx), sum / 2); 
  
  cout << ans << endl;
}

//First time I thought I can sort the array every time and decrease the two largest elements
//untill the second element becomes 0
//But this is O(N log N) for sorting every time, which is too slow for large N.

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;
  
  vector<int> num(N);
  for(int i = 0; i < N; i++){
    cin >> num[i];
  }
  
  int ans = 0;
  int sum = accumulate(num.begin(), num.end(), 0) / 2;
  for(int i = 0; i <= sum; i++){
    sort(num.begin(), num.end(), greater<int>());
    if(num[1] != 0){
      num[0]--;
      num[1]--;
      ans++;
    }
  }
  cout << ans << endl;
}
*/