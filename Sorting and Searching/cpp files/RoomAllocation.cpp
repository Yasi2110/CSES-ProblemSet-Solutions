#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
struct Client{
    int l, r, nom, br;
};
Client a[MAXN];

bool sortfunc(Client a1, Client a2) { return a1.l < a2.l; }
bool sortfunc2(Client a1, Client a2) { return a1.nom < a2.nom; }

int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a[i].l>>a[i].r;
        a[i].nom = i;
    }
    sort(a+1, a+n+1, sortfunc);

    priority_queue<pair<int, int>> q;
    int br = 0;
    for(i=1;i<=n;i++) {
        if(q.empty() || -q.top().first >= a[i].l) {
            a[i].br = ++br;
            q.push({-a[i].r, a[i].br});
        }
        else {
            a[i].br = q.top().second;
            q.pop();
            q.push({-a[i].r, a[i].br});
        }
    }

    sort(a+1, a+n+1, sortfunc2);

    cout<<br<<endl;
    for(i=1;i<=n;i++) cout<<a[i].br<<" ";
    cout<<endl;

    return 0;
}
