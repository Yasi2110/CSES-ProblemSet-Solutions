#include <bits/stdc++.h>
using namespace std;

int n, x;
const int MAXN = 2e5+1;
int a[MAXN];
set<int> s;

int Find(int k) {
    for(int i=n;i>=1;i--)
        if(a[i] == k) return i;
}

int main()
{
    cin>>n>>x;
    int i, br=0;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        s.insert(a[i]);
    }

    for(i=1;i<=n;i++) {
        if(s.find(x-a[i]) != s.end()) {
            int pos = Find(x-a[i]);
            if(i != pos) {
                cout<<i<<" "<<pos<<"\n";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";

    return 0;
}
