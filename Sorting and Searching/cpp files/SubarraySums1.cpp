#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int a[MAXN];
long long sum[MAXN];
set<long long> st;

int main()
{
    int n, x, i;
    cin>>n>>x;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];
        st.insert(sum[i]);
    }

    int ans = 0;
    for(i=1;i<=n;i++) {
        if(st.find(x+sum[i-1]) != st.end()) ans++;
    }
    cout<<ans<<endl;

    return 0;
}
