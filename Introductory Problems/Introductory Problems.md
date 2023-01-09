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


