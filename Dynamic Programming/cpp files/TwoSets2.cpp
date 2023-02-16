#include <bits/stdc++.h>
using namespace std;

int n;
int const MAXN = 501;
int const MAXDIF = 125126;
long long const MOD = 1e9+7;
long long dp[MAXN][MAXDIF];

int main()
{
    int i, j;
    cin>>n;
    dp[1][1] = 1;
    for(i=2;i<=n;i++) {
        for(j=0;j<MAXDIF-i;j++) {
            dp[i][j] = dp[i-1][abs(j-i)] + dp[i-1][j+i];
            dp[i][j]%= MOD;
        }
    }
    if(dp[n][0]%2 != 0) dp[n][0]+= MOD;
    cout<<(dp[n][0]/2)%MOD<<endl;

    return 0;
}
