#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 1e5+1;
const long long MOD = 1e9+7;
long long dp[MAXN][101];
int a[MAXN];

int main()
{
    int i, j;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];

    if(a[1] == 0) fill(dp[1]+1, dp[1]+m+1, 1);
    else  dp[1][a[1]] = 1;

    for(i=2;i<=n;i++) {
        for(j=1;j<=m;j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
            dp[i][j]%= MOD;
            if(a[i] != j && a[i] != 0) dp[i][j] = 0;
        }
    }
    long long sum = 0;
    for(i=1;i<=m;i++) {
        sum+= dp[n][i];
        sum%= MOD;
    }
    cout<<sum<<endl;

    return 0;
}
