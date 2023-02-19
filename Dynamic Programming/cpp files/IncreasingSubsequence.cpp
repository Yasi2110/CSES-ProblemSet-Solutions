#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
int a[MAXN];
set<int> st;
set<int>::iterator it;
map<int, int> newval;
int fen[MAXN];

int rsq(int k) {
    int res = 0;
    while(k > 0) {
        res = max(res, fen[k]);
        k = (k&(k+1))-1;
    }
    return res;
}

void update(int k, int newmax) {
    while(k < MAXN) {
        fen[k] = max(fen[k], newmax);
        k = k|(k+1);
    }
}

int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        st.insert(a[i]);
    }

    int tek = 0;
    for(it=st.begin();it!=st.end();++it)
        newval[*it] = ++tek;

    for(i=1;i<=n;i++) a[i] = newval[a[i]];

    int Max = 0;
    for(i=1;i<=n;i++) {
        int tans = rsq(a[i]-1) + 1;
        update(a[i], tans);
        Max = max(Max, tans);
    }
    cout<<Max<<endl;

    return 0;
}
