#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  
  cin >> S;
  
  S.push_back('s');
  
  cout << S << endl;
  
  return 0;
}

/*另一种方法，本质上是文字列的链接
int main(){
  string S;
  
  cin >> S;

  cout << S + 's' << endl;
  
  return 0;
}
*/