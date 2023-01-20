#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int a[MAXN];
bool sortfunc(int a1, int a2) { return a1 > a2; }

int main()
{
    int n, x, i;
    cin>>n>>x;
    for(i=1;i<=n;i++) cin>>a[i];

    sort(a+1, a+n+1, sortfunc);
    int cur = n, br = 0;

    for(i=1;i<=cur;i++) {
        if(a[i] + a[cur] <= x) cur--;
        br++;
    }
    cout<<br<<endl;

    return 0;
}
