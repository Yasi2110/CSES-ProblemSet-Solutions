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
