#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 1e6+1;
const long long MOD = 1e9+7;
long long dp[MAXN];

int main()
{
    int i;
    cin>>n;
    dp[0] = 1;
    for(i=1;i<=n;i++) {
        dp[i] = dp[i-1];
        if(i >= 2) dp[i]+= dp[i-2];
        if(i >= 3) dp[i]+= dp[i-3];
        if(i >= 4) dp[i]+= dp[i-4];
        if(i >= 5) dp[i]+= dp[i-5];
        if(i >= 6) dp[i]+= dp[i-6];
        dp[i]%= MOD;
    }
    cout<<dp[n]<<endl;

    return 0;
}
