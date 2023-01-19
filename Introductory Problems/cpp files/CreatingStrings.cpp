#include <bits/stdc++.h>
using namespace std;

int n, br[26];
vector<int> let;

void MakePermutation(string s) {
    if(s.size() == n) {
        cout<<s<<endl;
        return;
    }
    for(int i=0;i<let.size();i++) {
        if(br[let[i]] > 0) {
            br[let[i]]--;
            MakePermutation(s+(char)(let[i]+'a'));
            br[let[i]]++;
        }
    }
}

int main()
{
    string s;
    cin>>s;
    n = s.size();
    int i, j;
    for(i=0;i<s.size();i++) br[s[i]-'a']++;
    for(i=0;i<26;i++)
        if(br[i] > 0) let.push_back(i);

    int countt = 1;
    for(i=1;i<=s.size();i++)  countt*= i;
    for(i=0;i<let.size();i++)
        for(j=1;j<=br[let[i]];j++)
            countt/= j;
    cout<<countt<<endl;
    MakePermutation("");

    return 0;
}
