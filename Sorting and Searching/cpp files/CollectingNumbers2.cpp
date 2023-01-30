#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 2e5+2;
struct El {
    int st, pos;
};
El a[MAXN];
int b[MAXN];
bool sortfunc(El a1, El a2) { return a1.st < a2.st; }

int main()
{
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++) {
        cin>>b[i];
        a[i].st = b[i];
        a[i].pos = i;
    }
    sort(a+1, a+n+1, sortfunc);

    int br = 1;
    for(i=2;i<=n;i++)
        if(a[i-1].pos > a[i].pos) br++;

    for(i=1;i<=m;i++) {
        int p, q;
        cin>>p>>q;
        swap(b[p], b[q]);
        p = b[p];
        q = b[q];
        if(p > q) swap(p, q);
        if(a[p-1].pos > a[p].pos) br--;
        if(a[p].pos > a[p+1].pos) br--;
        if(p != q-1 && a[q-1].pos > a[q].pos) br--;
        if(a[q].pos > a[q+1].pos) br--;
        swap(a[p], a[q]);
        if(a[p-1].pos > a[p].pos) br++;
        if(a[p].pos > a[p+1].pos) br++;
        if(p != q-1 && a[q-1].pos > a[q].pos) br++;
        if(a[q].pos > a[q+1].pos) br++;
        cout<<br<<endl;
    }

    return 0;
}

