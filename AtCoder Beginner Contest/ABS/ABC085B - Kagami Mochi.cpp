#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  unordered_map<int, int> mochi;
  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    mochi[tmp]++;
  }
  cout << mochi.size() << endl;
}