#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
struct Task{
    int a, d;
};
Task t[MAXN];

bool sortfunc(Task t1, Task t2) { return t1.a < t2.a; }

int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>t[i].a>>t[i].d;
    sort(t+1, t+n+1, sortfunc);

    long long time = 0, ans = 0;
    for(i=1;i<=n;i++) {
        time+= t[i].a;
        ans+= t[i].d - time;
    }
    cout<<ans<<endl;
}
