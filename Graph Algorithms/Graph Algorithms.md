# Graph Algorithms

## [Counting rooms](https://cses.fi/problemset/task/1192)
We built a graph using the floor cells as vertexes and built the edges to connect every two floor cells between which you can move directly. To find the number of rooms we have to find the number of connected parts of the graph. This we do using dfs(depth first search).  
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int n, m;
char a[1001][1001];
const int MAXT = 1e6+1;
vector<int> v[MAXT];
vector<int> edg;
bool fl[MAXT];
 
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
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>a[i][j];
 
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++) {
            if(a[i][j] == '.') {
                edg.push_back((i-1)*m+j);
                if(a[i-1][j] == '.') {
                    v[(i-1)*m+j].push_back((i-2)*m+j);
                    v[(i-2)*m+j].push_back((i-1)*m+j);
                }
                if(a[i+1][j] == '.') {
                    v[(i-1)*m+j].push_back(i*m+j);
                    v[i*m+j].push_back((i-1)*m+j);
                }
                if(a[i][j-1] == '.') {
                    v[(i-1)*m+j].push_back((i-1)*m+j-1);
                    v[(i-1)*m+j-1].push_back((i-1)*m+j);
                }
                if(a[i][j+1] == '.') {
                    v[(i-1)*m+j].push_back((i-1)*m+j+1);
                    v[(i-1)*m+j+1].push_back((i-1)*m+j);
                }
            }
        }
    }
 
    int br = 0;
    for(i=0;i<edg.size();i++) {
        if(fl[edg[i]] == 0) {
            br++;
            Dfs(edg[i]);
        }
    }
    cout<<br<<endl;
 
    return 0;
}
```

## [Labyrinth](https://cses.fi/problemset/task/1193)
We use the same idea as in the previous task and built a graph. To find whether there is a path between A and B we use bfs(breadth first search). To recreate the shortest path between A and B we keep for every vertex which is it's previous one in the bfs. 
```cpp
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
```

## [Building Roads](https://cses.fi/problemset/task/1666)
We have to make the graph connected. To do so with minimum number of roads, we have to add new roads between the connected parts of the graph. To find them we use dfs.
```cpp
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
```
