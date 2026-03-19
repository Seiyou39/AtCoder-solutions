//循环,最简单的方法,但不适用于K非常大时,会超时.
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K, total_eat, years;
  cin >> N >> K;
  
  total_eat = N;
  years = 0;
  while(total_eat < K){
    N++;
    total_eat += N;
    years++;
  }
  
  cout << years <<endl;
  
  return 0;
}

//解公式法
//N + (N+1) + (N+2) + ... + (N+years) >= K
//(2N + years) * (1 + years) / 2 >= K
//years^2 + (2N + 1) * years + 2N - 2K >= 0
//解这个不等式,得到years的最小整数解.
//二次方程求根公式(-b +- sqrt(b^2 - 4ac)) / 2a
//a = 1, b = 2N + 1, c = 2N - 2K
//所以years = ceil((-b + sqrt(b^2 - 4ac)) / 2a)
/*
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  
  double a = 1.0, b = 2.0 * N + 1.0, c = 2.0 * N - 2.0 * K;
  double discriminant = b * b - 4.0 * a * c;
  double root = (-b + sqrt(discriminant)) / (2.0 * a);
  
  int years = ceil(root);
  
  cout << years << endl;
  
  return 0;
}
*/

//解二分法
/*#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  
  int left = 0, right = K; //years的范围是0到K
  while(left < right){
    int mid = left + (right - left) / 2;
    long long total_eat = (2LL * N + mid) * (mid + 1) / 2; //注意防止溢出,使用long long
    
    if(total_eat >= K){
      right = mid; //尝试更小的years
    } else {
      left = mid + 1; //需要更多的years
    }
  }
  
  cout << left << endl; //left和right最终会收敛到同一个值
  
  return 0;
}
*/