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

## [Playlist](https://cses.fi/problemset/task/1141)
We keep the songs that are in the current subsequence in a set and also the position that this subsequence starts at. We go through every songs and we add it to the set. If that song already exists in the set, we remove elements from the start of the subsequence while we are able to add the current song to it, i.e. when we add the song the subsequence stays unique. The answear is the max of all unique subsequences we have found.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int n, maxx;
const int MAXN = 2e5+1;
int a[MAXN];
set<int> s;
 
int main()
{
    int i, start = 1;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
 
    for(i=1;i<=n;i++) {
        while(s.find(a[i]) != s.end()) {
            s.erase(s.find(a[start]));
            start ++;
        }
        s.insert(a[i]);
        maxx = max(maxx, i-start+1);
    }
    cout<<maxx<<endl;
 
    return 0;
}
```

## [Towers](https://cses.fi/problemset/task/1073)
We go through every cube and put it on the first tower we can, i.e. the tower with smallest last cube that is bigger than the current one. If that is not possible we built new tower using the current cube.
```cpp
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
```

## [Traffic Lights](https://cses.fi/problemset/task/1163)
We use two sets - one to keep the current distances between every two consecutive traffic lights and one two keep the positions of the traffic lights. We simulate the process using these two sets. After every new traffic light the answear is the last element from the first set(the largest element).
```cpp
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
```

## [Josephus Problem 1](https://cses.fi/problemset/task/2162)
To simulate the process discribed in the task we use two vectors. In the first one are the numbers of the children that have left. We go through the elements of this vector, print every second one of them and keep in the other vector the numbers that we have not print - these are the numbers that have left for the next tour. After we have done that we make the first vector equal to the second one, i.e. the numbers left after the last tour. We do all of this because just erasing from a vector or array is too slow.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> v, v2;
 
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++) v.push_back(i);
 
    while(v.size() != 1) {
        for(i=1;i<v.size();i+=2) {
            cout<<v[i]<<" ";
            v2.push_back(v[i-1]);
        }
        if(v.size()%2 == 1)
            v2.insert(v2.begin(), v[v.size()-1]);
        v = v2;
        v2.clear();
    }
    cout<<v[0]<<endl;
 
    return 0;
}
```

## [Josephus Problem 2]()
The idea we use in the previous task would be too slow for some bigger ks. So we use a tree structure to simulate the process discribed in the task.
```cpp
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
```

## [Nested Ranges Check](https://cses.fi/problemset/task/2168)
First we sort the ranges increasingly by their left sides. To find whether some other range contains the current one, we find the max right end from all ranges before the current one. We already know that the left end of the current interval is bigger than all left ends of the privious ones. So if the max is bigger than the right end of the current interval, there is a range that contains it. We use the same strategy to find if the current interval contains other range, but this time we go through the ranges in reverse order.
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+1;
struct Range {
    int l, r, nom;
};
Range a[MAXN];

bool sortfunc(Range a1, Range a2) {
    return a1.l < a2.l || (a1.l == a2.l && a1.r > a2.r);
}

bool in[MAXN], out[MAXN];

int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)  {
        cin>>a[i].l>>a[i].r;
        a[i].nom = i;
    }
    sort(a+1, a+n+1, sortfunc);

    int maxx = a[1].r;
    for(i=2;i<=n;i++) {
        if(a[i].r <= maxx) out[a[i].nom] = 1;
        else maxx = a[i].r;
    }
    int minn = a[n].r;
    for(i=n-1;i>=1;i--) {
        if(minn <= a[i].r) in[a[i].nom] = 1;
        else minn = a[i].r;
    }

    for(i=1;i<=n;i++) cout<<in[i]<<" ";
    cout<<endl;
    for(i=1;i<=n;i++) cout<<out[i]<<" ";

    return 0;
}
```

## [Nested Ranges Count](https://cses.fi/problemset/task/2169)
We use the same idea, but this time we have also to count the number of ranges. If we go through every of the ranges to count them that will be too slow, so we use fenwick tree instead. The only problem is that the numbers we have for left and right end are too big and we can't make an array with 10^9 elements. But we don't care what exactly these numbers are, only which is bigger and which smaller. So we give new values to the left and right ends but keep this condition. For example the smallest number becomes 1, the next 2 etc.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int n;
const int MAXN = 2e5+1;
int Size;
struct Range {
    int l, r, nom;
};
Range a[MAXN];
 
bool sortfunc(Range a1, Range a2) {
    return a1.l < a2.l || (a1.l == a2.l && a1.r > a2.r);
}
 
int in[MAXN], out[MAXN];
 
set<int> val;
set<int>::iterator it;
map<int, int> newval;
int fen[2*MAXN];
 
void update(int k) {
    while(k <= Size) {
        fen[k]++;
        k = k|(k+1);
    }
}
 
int query(int k) {
    int res = 0;
    while(k > 0) {
        res+= fen[k];
        k = (k&(k+1))-1;
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int i;
    cin>>n;
    for(i=1;i<=n;i++)  {
        cin>>a[i].l>>a[i].r;
        a[i].nom = i;
        val.insert(a[i].l);
        val.insert(a[i].r);
    }
    sort(a+1, a+n+1, sortfunc);
 
    int tek = 0;
    for(it=val.begin();it!=val.end();++it)
        newval[*it] = ++tek;
    Size = tek;
    for(i=1;i<=n;i++) {
        a[i].l = newval[a[i].l];
        a[i].r = newval[a[i].r];
    }
 
    for(i=1;i<=n;i++) {
        out[a[i].nom] = i-1-query(a[i].r-1);
        update(a[i].r);
    }
    fill(fen, fen+Size+1, 0);
    for(i=n;i>=1;i--) {
        in[a[i].nom] = query(a[i].r);
        update(a[i].r);
    }
 
    for(i=1;i<=n;i++) cout<<in[i]<<' ';
    cout<<'\n';
    for(i=1;i<=n;i++) cout<<out[i]<<' ';
 
    return 0;
}
```

## [Room Allocation](https://cses.fi/problemset/task/1164)
First we sort all the intervals by there left side than we start putting the people in rooms as we put a person in a new room only if there is no other one that we already used and now its empty. To do this we use a priority queue in which we store all the right sides of the intervals that currently are in a room(or just left it and no one replaced them). We add a new room only when the first element in the queue is larger than the left side of the current element(the first person to leave, leaves after the current person arrives). Because the priority queue sorts the elements in decreasing order(and we need to be in increasing order) we put all the elements in the queue with negative sign.
```cpp
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
```

## [Factory Machines](https://cses.fi/problemset/task/1620)
To solve the problem we use binary search on the answer. In the function Solve we check whether for a sertain amount of time k, we can do t or more products. If that is possible we try for a smaller k, otherwise for a larger. 
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int n, t;
const int MAXN = 2e5+1;
int a[MAXN];
 
bool Solve(long long k) {
    long long prod = 0;
    for(int i=1;i<=n;i++) {
        prod += k/a[i];
        if(prod >= t) return true;
    }
    return false;
}
 
int main()
{
    int i;
    cin>>n>>t;
    for(i=1;i<=n;i++) cin>>a[i];
 
    long long l=1, r = 1e18;
    while(l<=r) {
        long long mid = (l+r)/2;
        if(Solve(mid)) r = mid-1;
        else l = mid+1;
    }
    cout<<l<<endl;
 
    return 0;
}
```

## [Tasks and Deadlines](https://cses.fi/problemset/task/1630)
The reward for a task i is d[i]-f[i](deadline - finishing time), so the sum of all rewards will be d[1]+d[2]+..+d[n]-(f[1]+f[2]+..+f[n]). So after the deadlines are fixed, the rewards sum will be max when the sum of fs is min. That happens when we process the task sorted by their duration times.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int n;
const int MAXN = 2e5+1;
struct Task{
    int a, d;
};
Task t[MAXN];
 
bool sortfunc(Task t1, Task t2) { return t1.a < t2.a; }
 
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>t[i].a>>t[i].d;
    sort(t+1, t+n+1, sortfunc);
 
    long long time = 0, ans = 0;
    for(i=1;i<=n;i++) {
        time+= t[i].a;
        ans+= t[i].d - time;
    }
    cout<<ans<<endl;
}
```

## [Reading Books](https://cses.fi/problemset/task/1631)
The answer is just the sum of all required times because always can be find a way where the two people аre reading different books. The only case where that is not true is when there is a book so long that the time for both of the people to read it seperatly is more than the sum off all required times. 
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, a, i;
    long long sum = 0, maxx = 0;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>a;
        sum+= a;
        if(maxx < a) maxx = a;
    }
    cout<<max(sum, 2*maxx)<<endl;
 
    return 0;
}
```

## [Nearest Smaller Values](https://cses.fi/problemset/task/1645)
We go through the elements in reversed order and start adding them in a stack. When we have to add the i-th element, we first check whether the top of the stack is a bigger number. If that's true than the answer for the number that is on top of the stack is the i-th position. After we already find the answer for it, we erase the top element from the stack. We do this while it's possible.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5+1;
int a[MAXN];
int ans[MAXN];
 
int main()
{
    int n, i;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    stack<int> st, pos;
    for(i=n;i>=1;i--) {
        while(!st.empty() && a[i] < st.top()) {
            ans[pos.top()] = i;
            st.pop(); pos.pop();
        }
        st.push(a[i]); pos.push(i);
    }
 
    for(i=1;i<=n;i++) cout<<ans[i]<<" ";
 
    return 0;
}
```

## [Subarrays Sums 1](https://cses.fi/problemset/task/1660)
In the array sum we keep the sum of all elements from 1 to i. Then we go through every position and find whether there is a subarray starting from this position with sum x. To do this in O(1) we use set.
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5+1;
int a[MAXN];
long long sum[MAXN];
set<long long> st;
 
int main()
{
    int n, x, i;
    cin>>n>>x;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];
        st.insert(sum[i]);
    }
 
    int ans = 0;
    for(i=1;i<=n;i++) {
        if(st.find(x+sum[i-1]) != st.end()) ans++;
    }
    cout<<ans<<endl;
 
    return 0;
}
```
