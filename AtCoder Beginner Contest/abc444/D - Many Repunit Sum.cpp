//题目思路不难，但如何实现花了点时间。
//一开始想着用幂次和公式，但发现计算过程中会溢出，且实现较为复杂。
//后来根据ChatGPT的提示，想到可以统计每个数字出现的次数，然后计算每个位上的和，最后处理进位。
//在发现40就是39个1，20就是19个1后，意识到只需要统计每个数字出现的次数即可。
//比如出现了数字40，那就代表前39位上都要加1。
//但是在实现过程中，想不到40 30 20 10这种情况该如何处理，不知到怎么储存并计算每个位上的和。
//后来参考了ChatGPT的代码，发现出现了40一次，那么前39位都要加1次1，如果出现了40两次，那么前39位都要加2次1。
//如果没有出现39，那么第39位只取决于40的出现次数。
//所以每一位ge[i]表示大于等于i的数字的个数，它取决于前一位ge[i+1]和当前位cnt[i]。举例，ge[35]时大于35的数字的个数，在上面40 30 20 10中，
//只有40大于35，所以ge[35]=1；而ge[30]时，大于30的数字有40和30，所以ge[30]=ge[31]+cnt[30]=1+1=2。
//这样就能计算出每个位上的和，然后处理进位即可。
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);//关闭C的stdio与C++的iostream的同步
    cin.tie(nullptr);//cin和cout不再互相绑定，cin执行后不会自动flush cout

    int N;
    cin >> N;

    const int MAXA = 200000;

    vector<long long> cnt(MAXA + 2, 0);//统计所有数字出现的次数。+2是为了防止越界。
    int maxA = 0;

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        cnt[x]++;
        maxA = max(maxA, x);
    }

    vector<long long> ge(maxA + 3, 0);//ge[i]表示大于等于i的数字的个数。+3是为了防止越界。
    for(int i = maxA; i >= 1; i--){
        ge[i] = ge[i+1] + cnt[i];
    }

    vector<int> ans;
    long long carry = 0;

    for(int p = 0; p < maxA; p++){
        long long cur = ge[p+1] + carry;//当前位置的和
        ans.push_back(cur % 10);
        carry = cur / 10;
    }

    while(carry){//处理最高位的进位
        ans.push_back(carry % 10);
        carry /= 10;
    }

    for(int i = (int)ans.size()-1; i >= 0; i--){
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
