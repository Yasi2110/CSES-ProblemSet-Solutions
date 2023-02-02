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
