#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int a[MAXN];
int ans[MAXN];

int main()
{
    int n, i;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    stack<int> st, pos;
    for(i=n;i>=1;i--) {
        while(!st.empty() && a[i] < st.top()) {
            ans[pos.top()] = i;
            st.pop(); pos.pop();
        }
        st.push(a[i]); pos.push(i);
    }

    for(i=1;i<=n;i++) cout<<ans[i]<<" ";

    return 0;
}
