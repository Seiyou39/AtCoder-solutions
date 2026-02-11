#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<string> words = {"maerd", "remaerd", "esare", "resare"};
  
  string S;
  cin >> S;
  bool can = true;
  reverse(S.begin(), S.end());
  for(int i = 0; i < S.size(); i++){
    if(S[i] == 'm' && S.substr(i + 1, 4) == "aerd"){
      i += 4; 
    }
    else if(S[i] == 'e' && S.substr(i + 1, 4) == "sare"){
      i += 4; 
    }
    else if(S[i] == 'r' && S.substr(i + 1, 5) == "esare"){
      i += 5; 
    }
    else if(S[i] == 'r' && S.substr(i + 1, 6) == "emaerd"){
      i += 6; 
    }
    else {
      can = false;
      break;
    }
  }
  if(can){
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
  
}

/* Another appraoch:
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());

    vector<string> words = {"maerd", "remaerd", "esare", "resare"};

    int i = 0;
    while (i < (int)S.size()) {
        bool ok = false;
        for (const string& w : words) {
            int m = (int)w.size();
            if (i + m <= (int)S.size() && S.substr(i, m) == w) {
                i += m;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
*/