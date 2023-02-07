#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 1e5+1;
vector<int> v[MAXN];
int team[MAXN];
bool fl;

void Dfs(int k) {
    if(fl) return;
    int t, i;
    if(team[k] == 1) t = 2;
    else  t = 1;
    for(i=0;i<v[k].size();i++) {
        if(team[v[k][i]] == team[k]) {
            fl = true;
            return;
        }
        if(team[v[k][i]] == 0) {
            team[v[k][i]] = t;
            Dfs(v[k][i]);
        }
    }
}

int main()
{
    int i;
    cin>>n>>m;
    for(i=1;i<=m;i++) {
        int p, q;
        cin>>p>>q;
        v[p].push_back(q);
        v[q].push_back(p);
    }

    for(i=1;i<=n;i++) {
        if(team[i] == 0) {
            team[i] = 1;
            Dfs(i);
            if(fl) break;
        }
    }
    if(fl) cout<<"IMPOSSIBLE\n";
    else {
        for(i=1;i<=n;i++) cout<<team[i]<<" ";
    }

    return 0;
}
