#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MAXN = 2e5+1;
int a[MAXN];
map<int, int> m;

int main()
{
    int i;
    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>a[i];

    int l = 1, br = 0;
    long long ans = 0;
    for(int r=1;r<=n;r++) {
        m[a[r]]++;
        if(m[a[r]] == 1) br++;
        while(br > k) {
            m[a[l]]--;
            if(m[a[l]] == 0) br--;
            l++;
        }
        ans+= r-l+1;
    }
    cout<<ans<<endl;

    return 0;
}
