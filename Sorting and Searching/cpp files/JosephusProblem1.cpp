#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v, v2;

int main()
{
    int i, start = 1;
    cin>>n;
    for(i=1;i<=n;i++) v.push_back(i);

    while(v.size() != 1) {
        for(i=1;i<v.size();i+=2) {
            cout<<v[i]<<" ";
            v2.push_back(v[i-1]);
        }
        if(v.size()%2 == 1)
            v2.insert(v2.begin(), v[v.size()-1]);
        v = v2;
        v2.clear();
    }
    cout<<v[0]<<endl;

    return 0;
}
