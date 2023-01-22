# Sorting and Searching

## [Distinct Numbers](https://cses.fi/problemset/task/1621)
First we sort the numbers then we count how many times there is a change in the array, i.e. the next number is different from the current one. This count is the number of different numbers in the array.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int a[MAXN];

int main()
{
    int n, i, br = 0;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];

    sort(a+1, a+n+1);

    for(i=1;i<=n;i++) {
        if(i == n || a[i] != a[i+1]) br++;
    }
    cout<<br<<endl;

    return 0;
}
```

## [Apartments](https://cses.fi/problemset/task/1084)
We sort the two arrays and start going through every element of the first one in increasing order. For every element we find the first apartment from the second array that is answearing the conditions for it and matching the current element with this apartment. This will get us the best answear because even if we have several apartments answearing the conditions for the current element we will match it with this apartment that will be of no use for the upcoming elements.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int a[MAXN], b[MAXN];

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    int i;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=m;i++) cin>>b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    int tek = 1, ans = 0;
    for(i=1;i<=n;i++) {
        while(tek <= m && a[i]-b[tek] > k) tek++;
        if(tek <= m && abs(a[i]-b[tek]) <= k) {
            ans++;  tek++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
```

## [Ferris Wheel](https://cses.fi/problemset/task/1090)
In one gondola we cannot put more than two children so we sort the array in decreasing order. We go through every element and put it in a separate gondola. If we can add the smallest element we have to the gondola with the current one we do. That will give us the optimal solution because we are putting the largest element we have with the smallest one we can, i.e. in any case if we can put the current element with another one we are doing it so the number of gondolas with two children is maximal.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5+1;
int a[MAXN];
bool sortfunc(int a1, int a2) { return a1 > a2; }
 
int main()
{
    int n, x, i;
    cin>>n>>x;
    for(i=1;i<=n;i++) cin>>a[i];
 
    sort(a+1, a+n+1, sortfunc);
    int cur = n, br = 0;
 
    for(i=1;i<=cur;i++) {
        if(a[i] + a[cur] <= x) cur--;
        br++;
    }
    cout<<br<<endl;
 
    return 0;
}
```

## [Concert Tickets](https://cses.fi/problemset/task/1091)
We use the data structure multiset to simulate the process discribed in the task.
```cpp
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
```

## [Restaurant Customers](https://cses.fi/problemset/task/1619)
First we put all the times from the input into one vector and sort them. We go through every element and if that element is a time of arrival we add one to the current number of customers into the restaurant, otherwise we substract one from it. The answear is the max of all current numbers of customers we get.
```cpp
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
```
