#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;
bool fl[MAXN];

int main()
{
    int n, a;
    cin>>n;
    for(int i=1;i<n;i++) {
        cin>>a;
        fl[a] = 1;
    }
    for(int i=1;i<=n;i++) {
        if(!fl[i]) {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
