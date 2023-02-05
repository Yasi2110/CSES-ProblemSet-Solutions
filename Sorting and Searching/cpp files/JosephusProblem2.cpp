#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> index_set;
index_set v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int n, k, i;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        v.insert(i);

    int tek = k;
    while(v.size() > 0) {
        tek%= v.size();
        auto ans = v.find_by_order(tek);
        cout<<*ans<<' ';
        v.erase(ans);
        tek+= k;
    }

    return 0;
}
