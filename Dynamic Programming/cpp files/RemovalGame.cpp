#include <bits/stdc++.h>
using namespace std;
 
int n;
const int MAXN = 5001;
int a[MAXN];
long long dp[MAXN][MAXN];
 
int main()
{
    int i, j;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
 
    for(i=n;i>=1;i--) {
        dp[i][i] = a[i];
        long long sum = a[i];
        for(j=i+1;j<=n;j++) {
            sum+= a[j];
            dp[i][j] = max(sum-dp[i+1][j], sum-dp[i][j-1]);
        }
    }
    cout<<dp[1][n]<<endl;
 
    return 0;
}
