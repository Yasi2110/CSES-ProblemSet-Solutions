#include <bits/stdc++.h>
using namespace std;

int n, x;
const int MAXX = 1e6+1;
const long long MOD = 1e9+7;
long long dp[MAXX];
int a[101];

int main()
{
    int i, j;
    cin>>n>>x;
    for(i=1;i<=n;i++) cin>>a[i];

    dp[0] = 1;
    for(i=1;i<=x;i++) {
        for(j=1;j<=n;j++)
            if(i >= a[j]) dp[i]+= dp[i-a[j]];
        dp[i]%= MOD;
    }
    cout<<dp[x]<<endl;

    return 0;
}
