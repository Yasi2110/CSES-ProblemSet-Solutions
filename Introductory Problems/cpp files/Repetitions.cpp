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
