#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-- ) {
        long long x, y, el;
        cin>>y>>x;
        // first finding in which
        // part(ring) of the spiral we are
        if(x >= y) {
            if(x%2 == 1) el = x*x - y + 1;
            else  el = (x-1)*(x-1) + y;
        }
        else
        if(x < y) {
            if(y%2 == 1) el = (y-1)*(y-1) + x;
            else el = y*y - x + 1;
        }
        cout<<el<<endl;
    }

    return 0;
}
