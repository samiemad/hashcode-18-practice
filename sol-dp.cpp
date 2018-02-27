#include <bits/stdc++.h>
using namespace std;

const char car[] = "MT";
int R, C, H, L;
char a[1002][1002];
int dp[51][51][51][51];
int SUM[1002][1002][2];

void preCalcSum() {
    for(int f=0; f<2; ++f){
        for(int r=0; r<R; ++r){
            for(int c=0; c<C; ++c){
                SUM[r+1][c+1][f] = SUM[r+1][c][f] + SUM[r][c+1][f] - SUM[r][c][f] + (a[r][c]==car[f]);
            }
        }
    }
}

int size(int x1, int y1, int x2, int y2){
    return abs(x2-x1+1) * abs(y2-y1+1);
}

int sum(int x1, int y1, int x2, int y2, bool f){
    return SUM[x2+1][y2+1][f] + SUM[x1][y1][f]
        - SUM[x2+1][y1][f] - SUM[x1][y2+1][f];
}

int val(int x1, int y1, int x2, int y2){
    if( sum(x1, y1, x2, y2, 0) >= L && sum(x1, y1, x2, y2, 1) >= L )
        return size(x1, y1, x2, y2);
    else
        return 0;
}

int calc(int x1, int y1, int x2, int y2){
    int &r = dp[x1][y1][x2][y2];
    if(r!=-1)
        return r;
    r = 0;
    if( size(x1,y1,x2,y2) <= H ){
        return r = val(x1,y1,x2,y2);
    }
    for(int x=x1; x<x2; ++x){
        r = max(r, calc(x1, y1, x, y2) + calc(x+1, y1, x2, y2) );
    }
    for(int y=y1; y<y2; ++y){
        r = max(r, calc(x1, y1, x2, y) + calc(x1, y+1, x2, y2) );
    }
    return r;
}

int main(){
    cin>>R>>C>>L>>H;

    for(int i=0; i<R; ++i)
        cin>>a[i];

    preCalcSum();
    memset(dp, -1, sizeof(dp));

    cout<<calc(0,0,R-1,C-1)<<"\n";

    return 0;
}
