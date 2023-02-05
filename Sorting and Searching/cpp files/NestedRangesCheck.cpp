#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
struct Range {
    int l, r, nom;
};
Range a[MAXN];

bool sortfunc(Range a1, Range a2) {
    return a1.l < a2.l || (a1.l == a2.l && a1.r > a2.r);
}

bool in[MAXN], out[MAXN];

int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)  {
        cin>>a[i].l>>a[i].r;
        a[i].nom = i;
    }
    sort(a+1, a+n+1, sortfunc);

    int maxx = a[1].r;
    for(i=2;i<=n;i++) {
        if(a[i].r <= maxx) out[a[i].nom] = 1;
        else maxx = a[i].r;
    }
    int minn = a[n].r;
    for(i=n-1;i>=1;i--) {
        if(minn <= a[i].r) in[a[i].nom] = 1;
        else minn = a[i].r;
    }

    for(i=1;i<=n;i++) cout<<in[i]<<" ";
    cout<<endl;
    for(i=1;i<=n;i++) cout<<out[i]<<" ";

    return 0;
}
