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

## [Movie Festival](https://cses.fi/problemset/task/1629/)
We sort the elements in the array by the second number - the end of every movie. We start going through the elemnts and if we can watch the current movie, i.e. it starts after the end of the last one we watched, we watch the current movie.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int n;
const int MAXN = 2e5+1;
struct El{
    int l, r;
};
El a[MAXN];
 
bool sortfunc(El a1, El a2) { return a1.r < a2.r; }
 
int main()
{
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r;
    sort(a+1, a+n+1, sortfunc);
 
    int endd = 0, br = 0;
    for(i=1;i<=n;i++) {
        if(endd <= a[i].l) {
            endd = a[i].r;
            br++;
        }
    }
    cout<<br<<endl;
 
    return 0;
}
```

## [Sum of Two Values](https://cses.fi/problemset/task/1640)
We go through every number and check if in the array exists an element equal to x minus the current number. We use set so we could find whether this element exists in O(1). If this element exists we find the position it is on and print the results.
```cpp
#include <bits/stdc++.h>
using namespace std;

int n, x;
const int MAXN = 2e5+1;
int a[MAXN];
set<int> s;

int Find(int k) {
    for(int i=n;i>=1;i--)
        if(a[i] == k) return i;
}

int main()
{
    cin>>n>>x;
    int i, br=0;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        s.insert(a[i]);
    }

    for(i=1;i<=n;i++) {
        if(s.find(x-a[i]) != s.end()) {
            int pos = Find(x-a[i]);
            if(i != pos) {
                cout<<i<<" "<<pos<<"\n";
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";

    return 0;
}
```

## [Maximum Subarray Sum](https://cses.fi/problemset/task/1643)
The thing we should notice is that there is no point of having a prefix with negative sum into the subarray. That way we always can just remove that prefix and increase the sum. So we start going through every element and adding it to the current sum, when that sum becomes negative we make it zero. As we said before there is no point of adding the prefix with that negative sum to the answear.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, i;
    cin>>n;
    long long br = 0, maxx = -1e9;
    for(i=1;i<=n;i++) {
        cin>>a;
        br+= a;
        maxx = max(maxx, br);
        if(br < 0) br = 0;
    }
    cout<<maxx<<endl;

    return 0;
}
```

## [Stick Lengths](https://cses.fi/problemset/task/1074)
The length that we are gonna make all sticks equal to is optimal when it is the median of the set of numbers we are given. A median is the element in the midlle of a sequence when the numbers in it are sorted.  
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
int a[MAXN];

int main()
{
    int i;
    long long ans = 0;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];

    sort(a+1, a+n+1);

    for(i=1;i<=n;i++) {
        ans+= abs(a[i] - a[n/2+1]);
    }
    cout<<ans<<endl;

    return 0;
}
```

## [Collecting Numbers](https://cses.fi/problemset/task/2216)
We collect the numbers in order from 1 to n so we sort the numbers that way but also rememeber the position on which they use to be. We go through these positions and every time the current position is smaller than the previous one we add one to the answear. That is so because every time that happens it means that we should go to the end and start a new round so we can collect the current number.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int n;
const int MAXN = 2e5+1;
struct El{
    int st, pos;
};
El a[MAXN];
 
bool sortfunc(El a1, El a2) { return a1.st < a2.st; }
 
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a[i].st;
        a[i].pos = i;
    }
    sort(a+1, a+n+1, sortfunc);
 
    int br = 1;
    for(i=2;i<=n;i++)
        if(a[i-1].pos > a[i].pos) br++;
    cout<<br<<endl;
 
    return 0;
}
```

## [Collecting Numbers 2](https://cses.fi/problemset/task/2217)
We use the same idea as in the previous task. First we find the answear for the input subsequence, after that for every operation of swap we swap the elements and calculate how that will change the answear. The idea we use to do so is that we first erase any changes that the numbers on the position we have to swap make to the answear and after that we add the changes they make after the swap.
```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 2e5+2;
struct El {
    int st, pos;
};
El a[MAXN];
int b[MAXN];
bool sortfunc(El a1, El a2) { return a1.st < a2.st; }

int main()
{
    int i;
    cin>>n>>m;
    for(i=1;i<=n;i++) {
        cin>>b[i];
        a[i].st = b[i];
        a[i].pos = i;
    }
    sort(a+1, a+n+1, sortfunc);

    int br = 1;
    for(i=2;i<=n;i++)
        if(a[i-1].pos > a[i].pos) br++;

    for(i=1;i<=m;i++) {
        int p, q;
        cin>>p>>q;
        swap(b[p], b[q]);
        p = b[p];
        q = b[q];
        if(p > q) swap(p, q);
        if(a[p-1].pos > a[p].pos) br--;
        if(a[p].pos > a[p+1].pos) br--;
        if(p != q-1 && a[q-1].pos > a[q].pos) br--;
        if(a[q].pos > a[q+1].pos) br--;
        swap(a[p], a[q]);
        if(a[p-1].pos > a[p].pos) br++;
        if(a[p].pos > a[p+1].pos) br++;
        if(p != q-1 && a[q-1].pos > a[q].pos) br++;
        if(a[q].pos > a[q+1].pos) br++;
        cout<<br<<endl;
    }

    return 0;
}
```
