# Introductory Problems

## [Weird Algorithm](https://cses.fi/problemset/task/1068)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;

    cout<<n<<' ';
    while(n != 1) {
        if(n%2 == 0) n/= 2;
        else n*= 3, n++;
        cout<<n<<' ';
    }
    cout<<endl;

    return 0;
}
```

## [Missing Number](https://cses.fi/problemset/task/1083)
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;
bool fl[MAXN];

int main()
{
    int n, a;
    cin>>n;
    for(int i=1;i<n;i++) {
        cin>>a;
        fl[a] = 1;
    }
    for(int i=1;i<=n;i++) {
        if(!fl[i]) {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
```

## [Repetitions](https://cses.fi/problemset/task/1069)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int maxx = 0, tek = 0;
    for(int i=0;i<s.size();i++) {
        tek++;
        if(i == s.size()-1 || s[i] != s[i+1]) {
            maxx = max(maxx, tek);
            tek = 0;
        }
    }
    cout<<maxx<<endl;

    return 0;
}
```

## [Increasing Array](https://cses.fi/problemset/task/1094)
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;
int n, a[MAXN];

int main()
{
    cin>>n;
    long long ans = 0;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=2;i<=n;i++) {
        if(a[i-1] > a[i]) {
            ans+= a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout<<ans<<endl;

    return 0;
}

```

## [Permutations](https://cses.fi/problemset/task/1070)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n;
    cin>>n;
    if(n == 1) cout<<1<<endl;
    else
    if(n <= 3) cout<<"NO SOLUTION"<<endl;
    else
    if(n == 4) cout<<"3 1 4 2"<<endl;
    else {
        for(i=n;i>0;i-=2) cout<<i<<" ";
        for(i=n-1;i>0;i-=2) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
```

## [Number Spiral](https://cses.fi/problemset/task/1071)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-- ) {
        long long x, y, el;
        cin>>y>>x;
        // first finding in which
        // part(ring) of the spiral we are
        if(x >= y) {
            if(x%2 == 1) el = x*x - y + 1;
            else  el = (x-1)*(x-1) + y;
        }
        else
        if(x < y) {
            if(y%2 == 1) el = (y-1)*(y-1) + x;
            else el = y*y - x + 1;
        }
        cout<<el<<endl;
    }

    return 0;
}
```

## [Two Knights](https://cses.fi/problemset/task/1072)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, ans;
    cin>>n;
    for(long long k=1;k<=n;k++) {
        if(k == 1) ans = 0;
        else
        ans+= 2*k*k*k - 3*k*k - 7*k + 16;
        cout<<ans<<endl;
    }

    return 0;
}
```
