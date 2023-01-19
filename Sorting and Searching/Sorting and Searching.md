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
