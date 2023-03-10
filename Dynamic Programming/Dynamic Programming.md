# Dynamic Programming

## [Dice Combinations](https://cses.fi/problemset/task/1633)
The answer for some sum n is the sum of the answers for n-1, n-2, n-3, n-4, n-5 and n-6. That is so because on every move we can add a dice with sum from 1 to 6.
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
For every sum x the answer is the minimum of one(the current coin that we add) plus the answer for x minus the current coin.
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
We use a similar idea to the previous task. But this time we want to calculate the number of possible combinations not the minimal number of coins. This time the answer for a sum x is the sum of all the answers for x minus any of the given coins.
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

## [Removing Digits](https://cses.fi/problemset/task/1637)
For every n the answer is one plus the minimum from all the answers of n minus any given digit of n.
```cpp
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
```

## [Grid Paths](https://cses.fi/problemset/task/1638)
The number of paths to some square form the grid (i, j) is the sum of the number of paths to (i-1, j) and (i, j-1).
```cpp
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
```

## [Array Discription](https://cses.fi/problemset/task/1746)
In dp[i][j] we keep the number of arrays that match the discription to the i-th elemnt and the i-th element is equal to j. We calculate the dp taking into account the numbers that we already know in the input array. The answer is the sum of all dp[n][i] where i is between 1 and m.
```cpp
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
```

## [Rectangle Cutting](https://cses.fi/problemset/task/1744)
To find the answer for some rectangle a x b we try all options for squares that we can cut and the answer if we cut that square. The answer for the rectangle is the minimum answer we've got from all the squares.
```cpp
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
```

## [Money Sums](https://cses.fi/problemset/task/1745)
To find all the sums we could possibly make we go through all the numbers we have one by one and add them to all already existing sums(made by the previous elements from the input).
```cpp
#include <bits/stdc++.h>
using namespace std;
 
vector<int> v;
const int MAXS = 1e5+1;
bool fl[MAXS];
 
int main()
{
    int n, i, j;
    cin>>n;
    v.push_back(0);
    for(i=1;i<=n;i++) {
        int a, d = v.size();
        cin>>a;
        for(j=0;j<d;j++) {
            if(fl[v[j]+a] == 0) {
                fl[v[j]+a] = 1;
                v.push_back(v[j]+a);
            }
        }
    }
    sort(v.begin(), v.end());
    cout<<v.size()-1<<"\n";
    for(i=1;i<v.size();i++)
        cout<<v[i]<<" ";
 
    return 0;
}
```

## [Removal Game](https://cses.fi/problemset/task/1097)
In dp[i][j] we keep the max score you can do as a first player in the interval from i to j in the array. To find dp[i][j] we find the max from the case when the first player gets the first number(i+1) and the case they get the last number(j-1).

```cpp
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
```

## [Two Sets](https://cses.fi/problemset/task/1093)
In dp[i][j] we keep the number of all pair sets including the numbers from 1 to i with the difference between the sums of their elements j. The answer will be dp[n][0].
```cpp
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
```

## [Increasing Subsequence](https://cses.fi/problemset/task/1145)
To find the answer for the elements from the first to the i-th element in the array we find the maximum answer from all the elements before the i-th whith value smaller than a[i] and add one(the current element). To do this we use fenwick tree. Because the numbers in the array are too big and we cannot make an array with 10^9 elements we revalue all the elements in the array but keep their order, i.e. when an element is bigger than another one it stays bigger.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int n;
const int MAXN = 2e5+1;
int a[MAXN];
set<int> st;
set<int>::iterator it;
map<int, int> newval;
int fen[MAXN];
 
int rsq(int k) {
    int res = 0;
    while(k > 0) {
        res = max(res, fen[k]);
        k = (k&(k+1))-1;
    }
    return res;
}
 
void update(int k, int newmax) {
    while(k < MAXN) {
        fen[k] = max(fen[k], newmax);
        k = k|(k+1);
    }
}
 
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        st.insert(a[i]);
    }
 
    int tek = 0;
    for(it=st.begin();it!=st.end();++it)
        newval[*it] = ++tek;
 
    for(i=1;i<=n;i++) a[i] = newval[a[i]];
 
    int Max = 0;
    for(i=1;i<=n;i++) {
        int tans = rsq(a[i]-1) + 1;
        update(a[i], tans);
        Max = max(Max, tans);
    }
    cout<<Max<<endl;
 
    return 0;
}
```

## [Projects](https://cses.fi/problemset/task/1140)
For every number between 1 and the max time of a project we find what is the max price we can get to this moment. To make this fast enough we revalue the numbers of the start and the end of all projects with as small numbers as we can but keep their order in time.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int n;
const int MAXN = 2e5+1;
set<int> st;
set<int>::iterator it;
map<int, int> newval;
struct El{
    int l, r, cost;
};
El a[MAXN];
 
bool sortfunc(El a1, El a2) { return a1.r <= a2.r; }
 
long long dp[2*MAXN];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int i;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a[i].l>>a[i].r>>a[i].cost;
        st.insert(a[i].l);
        st.insert(a[i].r);
    }
 
    int tek = 0;
    for(it=st.begin();it!=st.end();++it)
        newval[*it] = ++tek;
 
    for(i=1;i<=n;i++)
        a[i].l = newval[a[i].l],
        a[i].r = newval[a[i].r];
    sort(a+1, a+n+1, sortfunc);
 
    tek = 1;
    for(i=1;i<=2*n;i++) {
        dp[i] = dp[i-1];
        while(a[tek].r <= i && tek <= n) {
            dp[i] = max(dp[i], dp[a[tek].l-1]+a[tek].cost);
            tek++;
        }
    }
    cout<<dp[2*n]<<endl;
 
    return 0;
}
```
