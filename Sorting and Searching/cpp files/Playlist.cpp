#include <bits/stdc++.h>
using namespace std;

int n, maxx;
const int MAXN = 2e5+1;
int a[MAXN];
set<int> s;

int main()
{
    int i, start = 1;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];

    for(i=1;i<=n;i++) {
        while(s.find(a[i]) != s.end()) {
            s.erase(s.find(a[start]));
            start ++;
        }
        s.insert(a[i]);
        maxx = max(maxx, i-start+1);
    }
    cout<<maxx<<endl;

    return 0;
}
