#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;
  
  vector<string> Input;
  for(int i = 0; i < N; i++){
    string s;
    cin >> s;
    Input.push_back(s);
  }
  
  int max_str = (int)Input[0].size();
  for(int i = 1; i < N; i++){
    if(Input[i].size() > max_str){
      max_str =(int)Input[i].size();
    }
  }
  
  
  for(int i = 0; i < N; i++){

    int num = (max_str - Input[i].size()) / 2;

    string line = string(num, '.') + Input[i] + string(num, '.');//I can use string(num,char) instead of loop to print dots.
    cout << line << "\n";

    /*
    for(int j = 0 ; j < num; j++){
      cout << ".";
    }
    cout << Input[i];
    for(int j = 0 ; j < num; j++){
      cout << ".";
    }
    cout << "\n";
    */
  }
}