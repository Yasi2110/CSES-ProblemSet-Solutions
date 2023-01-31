#include <bits/stdc++.h>
using namespace std;

int n;
const long long MOD = 1e9+7;
char a[1001][1001];
long long dp[1001][1001];

int main()
{
    int i, j;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>a[i][j];

    dp[1][1] = 1;
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            dp[i][j]+= dp[i-1][j] + dp[i][j-1];
            dp[i][j]%= MOD;
            if(a[i][j] == '*') dp[i][j] = 0;
        }
    }
    cout<<dp[n][n]<<endl;

    return 0;
}
