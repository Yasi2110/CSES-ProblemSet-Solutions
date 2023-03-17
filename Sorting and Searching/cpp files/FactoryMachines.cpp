#include <bits/stdc++.h>
using namespace std;

int n, t;
const int MAXN = 2e5+1;
int a[MAXN];

bool Solve(long long k) {
    long long prod = 0;
    for(int i=1;i<=n;i++) {
        prod += k/a[i];
        if(prod >= t) return true;
    }
    return false;
}

int main()
{
    int i;
    cin>>n>>t;
    for(i=1;i<=n;i++) cin>>a[i];

    long long l=1, r = 1e18;
    while(l<=r) {
        long long mid = (l+r)/2;
        if(Solve(mid)) r = mid-1;
        else l = mid+1;
    }
    cout<<l<<endl;

    return 0;
}
