#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;
int dp[MAXN];

int main()
{
    int i, n;
    cin>>n;
    for(i=1;i<=n;i++) {
        dp[i] = 1e7;
        int k = i;
        while(k > 0) {
            dp[i] = min(dp[i], dp[i-k%10]+1);
            k/= 10;
        }
    }
    cout<<dp[n]<<endl;

    return 0;
}
