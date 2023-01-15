#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if((n*(n+1)/2)%2 != 0)  cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        vector<int> v1, v2;
        int start = 1;
        if(n%2 == 1) {
            v1.push_back(1);
            v1.push_back(2);
            v2.push_back(3);
            start = 4;
        }
        for(int i=start;i<=n;i+= 4) {
            v1.push_back(i);
            v1.push_back(i+3);
            v2.push_back(i+1);
            v2.push_back(i+2);
        }
        cout<<v1.size()<<endl;
        for(int i=0;i<v1.size();i++) cout<<v1[i]<<' ';
        cout<<endl;
        cout<<v2.size()<<endl;
        for(int i=0;i<v2.size();i++) cout<<v2[i]<<' ';
        cout<<endl;
    }

    return 0;
}
