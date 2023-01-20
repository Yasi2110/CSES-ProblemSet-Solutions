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
