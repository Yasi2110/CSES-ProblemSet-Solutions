#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 2e5+1;
multiset<int> a;
multiset<int>::iterator it;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin>>n>>m;
    int i, t;
    for(i=1;i<=n;i++) {
        cin>>t;
        a.insert(t);
    }

    for(i=1;i<=m;i++) {
        cin>>t;
        it = a.upper_bound(t);
        if(it == a.begin()) cout<<-1<<"\n";
        else {
            it--;
            cout<<*it<<"\n";
            a.erase(it);
        }
    }

    return 0;
}
