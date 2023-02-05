#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
int Size;
struct Range {
    int l, r, nom;
};
Range a[MAXN];

bool sortfunc(Range a1, Range a2) {
    return a1.l < a2.l || (a1.l == a2.l && a1.r > a2.r);
}

int in[MAXN], out[MAXN];

set<int> val;
set<int>::iterator it;
map<int, int> newval;
int fen[2*MAXN];

void update(int k) {
    while(k <= Size) {
        fen[k]++;
        k = k|(k+1);
    }
}

int query(int k) {
    int res = 0;
    while(k > 0) {
        res+= fen[k];
        k = (k&(k+1))-1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int i;
    cin>>n;
    for(i=1;i<=n;i++)  {
        cin>>a[i].l>>a[i].r;
        a[i].nom = i;
        val.insert(a[i].l);
        val.insert(a[i].r);
    }
    sort(a+1, a+n+1, sortfunc);

    int tek = 0;
    for(it=val.begin();it!=val.end();++it)
        newval[*it] = ++tek;
    Size = tek;
    for(i=1;i<=n;i++) {
        a[i].l = newval[a[i].l];
        a[i].r = newval[a[i].r];
    }

    for(i=1;i<=n;i++) {
        out[a[i].nom] = i-1-query(a[i].r-1);
        update(a[i].r);
    }
    fill(fen, fen+Size+1, 0);
    for(i=n;i>=1;i--) {
        in[a[i].nom] = query(a[i].r);
        update(a[i].r);
    }

    for(i=1;i<=n;i++) cout<<in[i]<<' ';
    cout<<'\n';
    for(i=1;i<=n;i++) cout<<out[i]<<' ';

    return 0;
}
