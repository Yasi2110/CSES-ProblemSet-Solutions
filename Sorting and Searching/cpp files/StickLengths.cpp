#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
int a[MAXN];

int main()
{
    int i;
    long long ans = 0;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];

    sort(a+1, a+n+1);

    for(i=1;i<=n;i++) {
        ans+= abs(a[i] - a[n/2+1]);
    }
    cout<<ans<<endl;

    return 0;
}
