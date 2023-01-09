#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n;
    cin>>n;
    if(n == 1) cout<<1<<endl;
    else
    if(n <= 3) cout<<"NO SOLUTION"<<endl;
    else
    if(n == 4) cout<<"3 1 4 2"<<endl;
    else {
        for(i=n;i>0;i-=2) cout<<i<<" ";
        for(i=n-1;i>0;i-=2) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
