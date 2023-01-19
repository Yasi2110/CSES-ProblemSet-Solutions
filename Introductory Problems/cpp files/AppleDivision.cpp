#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 21;
int a[MAXN];

long long Solve(long long sum, int p) {
    if(p == n+1) return sum;
    return min(Solve(sum+a[p], p+1),
               Solve(abs(sum-a[p]), p+1));
}

int main()
{
    cin>>n;
    int i;
    for(i=1;i<=n;i++) cin>>a[i];

    cout<<Solve(0, 1)<<endl;

    return 0;
}
