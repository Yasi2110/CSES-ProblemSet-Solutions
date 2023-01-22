#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, i;
    cin>>n;
    long long br = 0, maxx = -1e9;
    for(i=1;i<=n;i++) {
        cin>>a;
        br+= a;
        maxx = max(maxx, br);
        if(br < 0) br = 0;
    }
    cout<<maxx<<endl;

    return 0;
}
