#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
struct El{
    int st, pos;
};
El a[MAXN];

bool sortfunc(El a1, El a2) { return a1.st < a2.st; }

int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a[i].st;
        a[i].pos = i;
    }
    sort(a+1, a+n+1, sortfunc);

    int br = 1;
    for(i=2;i<=n;i++)
        if(a[i-1].pos > a[i].pos) br++;
    cout<<br<<endl;

    return 0;
}
