#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 1e5+1;
vector<int> v[MAXN];
int pr[MAXN];
bool fl[MAXN];

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

    queue<int> q;
    q.push(1);
    fl[1] = 1;
    while(!q.empty()) {
        int fr = q.front();
        if(fr == n) break;
        for(i=0;i<v[fr].size();i++) {
            if(!fl[v[fr][i]]) {
                fl[v[fr][i]] = 1;
                q.push(v[fr][i]);
                pr[v[fr][i]] = fr;
            }
        }
        q.pop();
    }
    if(pr[n] == 0) cout<<"IMPOSSIBLE\n";
    else {
        vector<int> ans;
        int tek = n;
        while(tek != 0) {
            ans.push_back(tek);
            tek = pr[tek];
        }
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<"\n";
        for(i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
    }

    return 0;
}
