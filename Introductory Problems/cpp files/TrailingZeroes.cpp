#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int br = 0, tek = 5;
    while(n/tek > 0) {
        br+= n/tek;
        tek*= 5;
    }
    cout<<br<<endl;

    return 0;
}
