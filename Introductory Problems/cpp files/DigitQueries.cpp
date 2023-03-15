#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-- ){
        long long k;
        cin>>k;
        long long help = 9, dig = 1;
        int ans[19], pos = 1;
        while(k > help*dig) {
            k-= help*dig;
            help*=10, dig++;
        }
        help/= 9;
        while(help > 0) {
            if(pos == 1) ans[pos] = 1;
            else  ans[pos] = 0;
            while(k > help*dig) {
                k-= help*dig;
                ans[pos] ++;
            }
            help/= 10; pos++;
        }
        cout<<ans[k]<<endl;
    }
    return 0;
}
