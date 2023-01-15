# Introductory Problems

## [Weird Algorithm](https://cses.fi/problemset/task/1068)
Printing the blanck spaces as a char not a string so the programm can be in the time limit.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;

    cout<<n<<' ';
    while(n != 1) {
        if(n%2 == 0) n/= 2;
        else n*= 3, n++;
        cout<<n<<' ';
    }
    cout<<endl;

    return 0;
}
```

## [Missing Number](https://cses.fi/problemset/task/1083)
In a bool array we write down which numbers we have gone through.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;
bool fl[MAXN];

int main()
{
    int n, a;
    cin>>n;
    for(int i=1;i<n;i++) {
        cin>>a;
        fl[a] = 1;
    }
    for(int i=1;i<=n;i++) {
        if(!fl[i]) {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
```

## [Repetitions](https://cses.fi/problemset/task/1069)
Keeping the count of consecutive characters then when the next character is different we compare this count to the maximum.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int maxx = 0, tek = 0;
    for(int i=0;i<s.size();i++) {
        tek++;
        if(i == s.size()-1 || s[i] != s[i+1]) {
            maxx = max(maxx, tek);
            tek = 0;
        }
    }
    cout<<maxx<<endl;

    return 0;
}
```

## [Increasing Array](https://cses.fi/problemset/task/1094)
When the previous element is bigger than the current one, we add the difference to the answear and make the current element equal to the previous one.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;
int n, a[MAXN];

int main()
{
    cin>>n;
    long long ans = 0;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=2;i<=n;i++) {
        if(a[i-1] > a[i]) {
            ans+= a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout<<ans<<endl;

    return 0;
}

```

## [Permutations](https://cses.fi/problemset/task/1070)
If n > 4 we first print the numbers from n, n-2, n-4... then print n-1, n-3, n-5...
Otherwise we can view it as a single case.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n;
    cin>>n;
    if(n == 1) cout<<1<<endl;
    else
    if(n <= 3) cout<<"NO SOLUTION"<<endl;
    else
    if(n == 4) cout<<"3 1 4 2"<<endl;
    else {
        for(i=n;i>0;i-=2) cout<<i<<" ";
        for(i=n-1;i>0;i-=2) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
```

## [Number Spiral](https://cses.fi/problemset/task/1071)
First finding in which part(circle) of the spiral we are in - that's the max(x, y). After that we add or subtract from the first number in the row/column the min(x, y) to get to the number in the cell we want.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-- ) {
        long long x, y, el;
        cin>>y>>x;
        if(x >= y) {
            if(x%2 == 1) el = x*x - y + 1;
            else  el = (x-1)*(x-1) + y;
        }
        else
        if(x < y) {
            if(y%2 == 1) el = (y-1)*(y-1) + x;
            else el = y*y - x + 1;
        }
        cout<<el<<endl;
    }

    return 0;
}
```

## [Two Knights](https://cses.fi/problemset/task/1072)
We find the answer for the table k x k using the answer for the previous table (k-1) x (k-1) and adding the possibilities where one of the knights or both are in the last row or the last column. After simplification we get to the formula below.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, ans;
    cin>>n;
    for(long long k=1;k<=n;k++) {
        if(k == 1) ans = 0;
        else
        ans+= 2*k*k*k - 3*k*k - 7*k + 16;
        cout<<ans<<endl;
    }

    return 0;
}
```

## [Two Sets](https://cses.fi/problemset/task/1092/)
Obviously we cant't divide it into two equal sets if the sum of the numbers n*(n+1)/2 is odd. That is happening when ether n or n+1 is even but it is not divisible by four. In all other cases we are deviding the numbers from 1 to n in groups of four - first group is 1,2,3,4 second one - 5,6,7,8 etc. In every group we get the first and the last number and put it into the first set, the middle two go to the second set. That way the sum in both sets stays the same. When n is odd the first group is only of 1, 2, 3. (1 and 2 - first set, 3 - second set)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if((n*(n+1)/2)%2 != 0)  cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        vector<int> v1, v2;
        int start = 1;
        if(n%2 == 1) {
            v1.push_back(1);
            v1.push_back(2);
            v2.push_back(3);
            start = 4;
        }
        for(int i=start;i<=n;i+= 4) {
            v1.push_back(i);
            v1.push_back(i+3);
            v2.push_back(i+1);
            v2.push_back(i+2);
        }
        cout<<v1.size()<<endl;
        for(int i=0;i<v1.size();i++) cout<<v1[i]<<' ';
        cout<<endl;
        cout<<v2.size()<<endl;
        for(int i=0;i<v2.size();i++) cout<<v2[i]<<' ';
        cout<<endl;
    }

    return 0;
}
```

## [Bit Strings](https://cses.fi/problemset/task/1617) 
For every bit we have two options. The answear is 2^n.
```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
    int n;
    cin>>n;
    long long br = 1;
    for(int i=1;i<=n;i++) {
        br*= 2;
        br%= MOD;
    }
    cout<<br<<endl;

    return 0;
}
```

## [Trailing Zeroes](https://cses.fi/problemset/task/1618)
The number of trailing zeroes in n! is the minimum of the number of twoes that take part in the product and the number of fives. Obviously this min is equal to the number of fives. But we have to notice that in 25 for example there are two fives, that is also true for 50, 75 etc. So for every number that is devisible by a degree of five we add one more to the ansewear.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int br = 0, tek = 5;
    while(n/tek > 0) {
        br+= n/tek;
        tek*= 5;
    }
    cout<<br<<endl;

    return 0;
}
```

## [Coin Piles](https://cses.fi/problemset/task/1754)
There are two conditions under which the two piles can be emptied - first is the sum of all coins is divisible by tree (in every move we get a total of tree coins), the second one - neither of the two piles isn't too big, i.e. even if in every move we get two coins from the big one, we still wouldn't empty it before the other pile is already emptied.
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-- ) {
        int a, b;
        cin>>a>>b;
        if(a < b) swap(a, b);
        if((a+b)%3 != 0 || a > 2*b) cout<<"NO"<<endl;
        else  cout<<"YES"<<endl;
    }

    return 0;
}
```
