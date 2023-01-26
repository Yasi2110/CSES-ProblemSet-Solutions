#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
struct El{
    int l, r;
};
El a[MAXN];

bool sortfunc(El a1, El a2) { return a1.r < a2.r; }

int main()
{
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r;
    sort(a+1, a+n+1, sortfunc);

    int endd = 0, br = 0;
    for(i=1;i<=n;i++) {
        if(endd <= a[i].l) {
            endd = a[i].r;
            br++;
        }
    }
    cout<<br<<endl;

    return 0;
}
