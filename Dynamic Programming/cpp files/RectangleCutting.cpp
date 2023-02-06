#include <bits/stdc++.h>
using namespace std;

int a, b;
int dp[501][501];

int Solve(int a, int b, int s) {
    int ans1 = dp[a][b-s] + dp[a-s][s];
    int ans2 = dp[a-s][b] + dp[s][b-s];
    return min(ans1, ans2);
}

int main()
{
    cin>>a>>b;
    int i, j, t;

    for(i=1;i<=a;i++) {
        for(j=1;j<=b;j++) {
            dp[i][j] = INT_MAX;
            for(t=1;t<=min(i,j);t++)
                dp[i][j] = min(dp[i][j], Solve(i, j, t)+1);
        }
    }
    cout<<dp[a][b]-1<<endl;

    return 0;
}
