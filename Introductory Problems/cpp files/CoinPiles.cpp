#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-- ) {
        int a, b;
        cin>>a>>b;
        if(a < b) swap(a, b);
        if((a+b)%3 != 0 || a > 2*b) cout<<"NO"<<endl;
        else  cout<<"YES"<<endl;
    }

    return 0;
}
