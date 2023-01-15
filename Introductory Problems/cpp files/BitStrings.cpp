#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
    int n;
    cin>>n;
    long long br = 1;
    for(int i=1;i<=n;i++) {
        br*= 2;
        br%= MOD;
    }
    cout<<br<<endl;

    return 0;
}
