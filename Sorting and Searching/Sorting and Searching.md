# Sorting and Searching

## [Distinct Numbers](https://cses.fi/problemset/task/1621)
First we sort the numbers then we count how many times there is a change in the array, i.e. the next number is different from the current one. This count is the number of different numbers in the array.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int a[MAXN];

int main()
{
    int n, i, br = 0;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];

    sort(a+1, a+n+1);

    for(i=1;i<=n;i++) {
        if(i == n || a[i] != a[i+1]) br++;
    }
    cout<<br<<endl;

    return 0;
}
```

## [Apartments](https://cses.fi/problemset/task/1084)
We sort the two arrays and start going through every element of the first one in increasing order. For every element we find the first apartment from the second array that is answearing the conditions for it and matching the current element with this apartment. This will get us the best answear because even if we have several apartments answearing the conditions for the current element we will match it with this apartment that will be of no use for the upcoming elements.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int a[MAXN], b[MAXN];

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    int i;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=m;i++) cin>>b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    int tek = 1, ans = 0;
    for(i=1;i<=n;i++) {
        while(tek <= m && a[i]-b[tek] > k) tek++;
        if(tek <= m && abs(a[i]-b[tek]) <= k) {
            ans++;  tek++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
```
