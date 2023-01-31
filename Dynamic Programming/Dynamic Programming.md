# Dynamic Programming

## [Dice Combinations](https://cses.fi/problemset/task/1633)
The answear for some sum n is the sum of the answears for n-1, n-2, n-3, n-4, n-5 and n-6. That is so because on every move we can add a dice with sum from 1 to 6.
```cpp
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
```

## [Minimizing Coins](https://cses.fi/problemset/task/1634)
For every sum x the answear is the minimum of one(the current coin that we add) plus the answear for x minus the current coin.
```cpp
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
```

## [Coin Combinations 1](https://cses.fi/problemset/task/1635)
We use a similar idea to the previous task. But this time we want to calculate the number of possible combinations not the minimal number of coins. This time the answear for a sum x is the sum of all the answears for x minus any of the given coins.
```cpp
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
```
