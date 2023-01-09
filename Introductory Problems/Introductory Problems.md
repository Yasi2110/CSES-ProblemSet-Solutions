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


