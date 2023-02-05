#include <bits/stdc++.h>
using namespace std;

char s[49];
bool fl[8][8];
int Ans = 0;

void Rec(int i, int x, int y) {
    if(i == 48 || (x == 7 && y == 1)) {
        if(x == 7 && y == 1 && i == 48) Ans++;
        return;
    }

    if((x == 7 || fl[x+1][y]) && (x == 1 || fl[x-1][y]))
        if(y > 1 && !fl[x][y-1] && y < 7 && !fl[x][y+1])
        return;

    if((y == 7 || fl[x][y+1]) && (y == 1 || fl[x][y-1]))
        if(x < 7 && !fl[x+1][y] && x > 1 && !fl[x-1][y])
        return;

    fl[x][y] = 1;
    if((s[i] == '?' || s[i] == 'D') && x < 7 && !fl[x+1][y])
        Rec(i+1, x+1, y);

    if((s[i] == '?' || s[i] == 'U') && x > 1 && !fl[x-1][y])
        Rec(i+1, x-1, y);

    if((s[i] == '?' || s[i] == 'R') && y < 7 && !fl[x][y+1])
        Rec(i+1, x, y+1);

    if((s[i] == '?' || s[i] == 'L') && y > 1 && !fl[x][y-1])
        Rec(i+1, x, y-1);
    fl[x][y] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin>>s;
    Rec(0, 1, 1);
    cout<<Ans<<'\n';

    return 0;
}
