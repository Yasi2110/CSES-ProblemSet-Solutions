#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 1e5+1;
vector<int> v[MAXN];
bool fl[MAXN];
vector<int> groups;

void Dfs(int k) {
    if(fl[k]) return;
    fl[k] = 1;
    for(int i=0;i<v[k].size();i++)
        Dfs(v[k][i]);
}

int main()
{
    int i, j;
    cin>>n>>m;
    for(i=1;i<=m;i++) {
        int p, q;
        cin>>p>>q;
        v[p].push_back(q);
        v[q].push_back(p);
    }

    for(i=1;i<=n;i++) {
        if(fl[i] == 0) {
            Dfs(i);
            groups.push_back(i);
        }
    }

    cout<<groups.size()-1<<endl;
    for(i=1;i<groups.size();i++)
        cout<<groups[i-1]<<" "<<groups[i]<<endl;

    return 0;
}
