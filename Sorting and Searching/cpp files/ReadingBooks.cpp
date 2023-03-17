#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, i;
    long long sum = 0, maxx = 0;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a;
        sum+= a;
        if(maxx < a) maxx = a;
    }
    cout<<max(sum, 2*maxx)<<endl;

    return 0;
}
