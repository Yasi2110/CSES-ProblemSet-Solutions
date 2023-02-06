#include <bits/stdc++.h>
using namespace std;

vector<int> v;
const int MAXS = 1e5+1;
bool fl[MAXS];

int main()
{
    int n, i, j;
    cin>>n;
    v.push_back(0);
    for(i=1;i<=n;i++) {
        int a, d = v.size();
        cin>>a;
        for(j=0;j<d;j++) {
            if(fl[v[j]+a] == 0) {
                fl[v[j]+a] = 1;
                v.push_back(v[j]+a);
            }
        }
    }
    sort(v.begin(), v.end());
    cout<<v.size()-1<<"\n";
    for(i=1;i<v.size();i++)
        cout<<v[i]<<" ";

    return 0;
}
