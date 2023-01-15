#include <bits/stdc++.h>
using namespace std;

int countt[26];

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) {
        countt[s[i]-'A']++;
    }
    int mid = -1, br = 0;
    for(int i=0;i<26;i++) {
        if(countt[i]%2 != 0) {
            br++;  mid = i;
            countt[mid]--;
        }
    }
    if(br > 1) cout<<"NO SOLUTION"<<endl;
    else {
        for(int i=0;i<26;i++) {
            for(int j=1;j<=countt[i]/2;j++)
                cout<<(char)(i+'A');
        }
        if(mid != -1) cout<<(char)(mid+'A');
        for(int i=25;i>=0;i--) {
            for(int j=1;j<=countt[i]/2;j++)
                cout<<(char)(i+'A');
        }
    }

    return 0;
}
