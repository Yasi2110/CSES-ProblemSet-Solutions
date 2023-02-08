#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 1e5+1;
vector<int> v[MAXN];
bool fl[MAXN];
int pr[MAXN], start = -1;

void Dfs(int k) {
    if(fl[k]) {
        start = k;
        return;
    }
    fl[k] = 1;
    for(int i=0;i<v[k].size();i++) {
        if(pr[k] == v[k][i]) continue;
        pr[v[k][i]] = k;
        Dfs(v[k][i]);
        if(start != -1) return;
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
        if(fl[i] == 0) {
            Dfs(i);
            if(start != -1) break;
        }
    }
    if(start == -1) cout<<"IMPOSSIBLE\n";
    else {
        vector<int> path;
        int tek = pr[start];
        path.push_back(start);
        while(tek != start) {
            path.push_back(tek);
            tek = pr[tek];
        }
        path.push_back(start);
        cout<<path.size()<<"\n";
        for(i=0;i<path.size();i++)
            cout<<path[i]<<" ";
    }

    return 0;
}
