#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, ans;
    cin>>n;
    for(long long k=1;k<=n;k++) {
        if(k == 1) ans = 0;
        else
        ans+= 2*k*k*k - 3*k*k - 7*k + 16;
        cout<<ans<<endl;
    }

    return 0;
}
