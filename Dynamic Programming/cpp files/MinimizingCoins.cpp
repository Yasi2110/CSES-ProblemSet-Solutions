#include <bits/stdc++.h>
using namespace std;

int n, x;
const int MAXX = 1e6+1;
int dp[MAXX], a[101];

int main()
{
    int i, j;
    cin>>n>>x;
    for(i=1;i<=n;i++) cin>>a[i];

    for(i=1;i<=x;i++) {
        dp[i] = 1e7;
        for(j=1;j<=n;j++)
            if(i >= a[j]) dp[i] = min(dp[i], dp[i-a[j]]+1);
    }
    if(dp[x] == 1e7) dp[x] = -1;
    cout<<dp[x]<<endl;

    return 0;
}
