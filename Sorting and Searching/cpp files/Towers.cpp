#include <bits/stdc++.h>
using namespace std;

multiset<int> s;
multiset<int>::iterator it;

int main()
{
    int n, p;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>p;
        it = s.upper_bound(p);
        if(it != s.end()) s.erase(it);
        s.insert(p);
    }
    cout<<s.size()<<endl;

    return  0;
}
