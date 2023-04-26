#include <bits/stdc++.h>
using namespace std;
 
int n;
const int MAXN = 2e5+1;
int a[MAXN], tsum[MAXN];
long long m[MAXN];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int i;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        tsum[i] = tsum[i-1] + a[i];
        tsum[i]%= n;
        if(tsum[i] < 0) tsum[i]+= n;
    }
 
    long long br = 0;
    for(i=n;i>=1;i--) {
        m[tsum[i]]++;
        br+= m[tsum[i-1]];
    }
    cout<<br<<endl;
 
    return 0;
}
