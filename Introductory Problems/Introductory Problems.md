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

