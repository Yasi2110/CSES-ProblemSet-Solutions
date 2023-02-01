#include <bits/stdc++.h>
using namespace std;

int x, n;
const int MAXN = 2e5+1;
multiset<int> ans;
set<int> lights;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int t;
    cin>>x>>n;
    lights.insert(0);
    lights.insert(x);
    ans.insert(x);
    while(n-- ) {
        cin>>t;
        int t1 = *(--lights.upper_bound(t));
        int t2 = *(lights.upper_bound(t));
        ans.erase(ans.find(t2-t1));
        ans.insert(t-t1);
        ans.insert(t2-t);
        lights.insert(t);
        cout<<*(--ans.end())<<' ';
    }

    return 0;
}
