#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];
const int MAXX = 1e6+1;
vector<int> v[MAXX];
int pr[MAXX];
bool fl[MAXX];

int main()
{
    int i, j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>a[i][j];

    int start, endd;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(a[i][j] == 'A') start = (i-1)*m + j;
            if(a[i][j] == 'B') endd = (i-1)*m + j;
            if(a[i][j] != '#') {
                if(a[i-1][j] != '#' && i > 1) {
                    v[(i-1)*m+j].push_back((i-2)*m+j);
                    v[(i-2)*m+j].push_back((i-1)*m+j);
                }
                if(a[i+1][j] != '#' && i < n) {
                    v[(i-1)*m+j].push_back(i*m+j);
                    v[i*m+j].push_back((i-1)*m+j);
                }
                if(a[i][j-1] != '#' && j > 1) {
                    v[(i-1)*m+j].push_back((i-1)*m+j-1);
                    v[(i-1)*m+j-1].push_back((i-1)*m+j);
                }
                if(a[i][j+1] != '#' && j < m) {
                    v[(i-1)*m+j].push_back((i-1)*m+j+1);
                    v[(i-1)*m+j+1].push_back((i-1)*m+j);
                }
            }
        }
    }

    queue<int> q;
    q.push(start);
    fl[start] = 1;
    while(!q.empty()) {
        int fr = q.front();
        if(fr == endd) break;
        for(i=0;i<v[fr].size();i++) {
            if(fl[v[fr][i]] == 0) {
                q.push(v[fr][i]);
                fl[v[fr][i]] = 1;
                pr[v[fr][i]] = fr;
            }
        }
        q.pop();
    }
    if(pr[endd] == 0) cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        string s;
        int tek = endd;
        while(tek != start) {
            if(tek-pr[tek] == -m) s+= 'U';
            if(tek-pr[tek] == m) s+= 'D';
            if(tek-pr[tek] == 1) s+= 'R';
            if(tek-pr[tek] == -1) s+= 'L';
            tek = pr[tek];
        }
        reverse(s.begin(), s.end());
        cout<<s.size()<<endl;
        cout<<s<<endl;
    }


    return 0;
}
