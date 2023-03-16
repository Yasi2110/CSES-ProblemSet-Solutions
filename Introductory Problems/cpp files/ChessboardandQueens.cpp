#include <bits/stdc++.h>
using namespace std;

char a[9][9];
int Ans = 0;

bool CheckPos(int x, int y) {
    if(a[x][y] != '.') return false;
    for(int i=1;i<=8;i++)
        if(a[x][i] == '#') return false;
    for(int i=1;i<=8;i++)
        if(a[i][y] == '#') return false;
    for(int i=1;x-i>0&&y-i>0;i++)
        if(a[x-i][y-i] == '#') return false;
    for(int i=1;x+i<=8&&y+i<=8;i++)
        if(a[x+i][y+i] == '#') return false;
    for(int i=1;x-i>0&&y+i<=8;i++)
        if(a[x-i][y+i] == '#') return false;
    for(int i=1;x+i<=8&&y-i>0;i++)
        if(a[x+i][y-i] == '#') return false;
    return true;
}

void Rec(int col) {
    if(col == 9) {
        Ans++;
        return;
    }
    for(int i=1;i<=8;i++) {
        if(CheckPos(i, col)) {
            a[i][col] = '#';
            Rec(col+1);
            a[i][col] = '.';
        }
    }
}

int main()
{
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            cin>>a[i][j];

    Rec(1);
    cout<<Ans<<endl;

    return 0;
}
