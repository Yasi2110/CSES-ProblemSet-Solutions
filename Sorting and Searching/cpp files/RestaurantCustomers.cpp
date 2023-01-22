#include <bits/stdc++.h>
using namespace std;

int n;
struct Element{
    int val, in;
};
vector<Element> a;

bool sortfunc(Element a1, Element a2) {
    return (a1.val < a2.val) ||
        (a1.val == a2.val && a1.in > a2.in);
}

int main()
{
    cin>>n;
    int i;
    for(i=1;i<=n;i++) {
        int p, q;
        cin>>p>>q;
        a.push_back({p, 1});
        a.push_back({q, -1});
    }

    sort(a.begin(), a.end(), sortfunc);

    int br = 0, maxx = 0;
    for(i=0;i<a.size();i++) {
        br+= a[i].in;
        maxx = max(maxx, br);
    }

    cout<<maxx<<endl;

    return 0;
}
