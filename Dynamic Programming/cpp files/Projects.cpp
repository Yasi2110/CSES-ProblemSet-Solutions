#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
set<int> st;
set<int>::iterator it;
map<int, int> newval;
struct El{
    int l, r, cost;
};
El a[MAXN];

bool sortfunc(El a1, El a2) { return a1.r <= a2.r; }

long long dp[2*MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int i;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a[i].l>>a[i].r>>a[i].cost;
        st.insert(a[i].l);
        st.insert(a[i].r);
    }

    int tek = 0;
    for(it=st.begin();it!=st.end();++it)
        newval[*it] = ++tek;

    for(i=1;i<=n;i++)
        a[i].l = newval[a[i].l],
        a[i].r = newval[a[i].r];
    sort(a+1, a+n+1, sortfunc);

    tek = 1;
    for(i=1;i<=2*n;i++) {
        dp[i] = dp[i-1];
        while(a[tek].r <= i && tek <= n) {
            dp[i] = max(dp[i], dp[a[tek].l-1]+a[tek].cost);
            tek++;
        }
    }
    cout<<dp[2*n]<<endl;

    return 0;
}
