#include <bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
struct Rect{
    int r,c,rr,cc;
    Rect(int r, int c, int rr, int cc) r:r, c:c, rr:rr, cc:cc {}
};
typedef pair<int,int> ii;

const char car[] = "MT";
int R, C, H, L;
char a[1002][1002];
int SUM[1002][1002];
vector<ii> pSiz;
vector<Rect> sol;

void preCalcSum() {
    for(int r=0; r<R; ++r){
        for(int c=0; c<C; ++c){
            SUM[r+1][c+1] = SUM[r+1][c] + SUM[r][c+1] - SUM[r][c] + (a[r][c]=='M'?1:-1);
        }
    }

    for(int i=1; i<=L; ++i){
        for(int j=1; j<=L; ++j){
            if(i*j>=2*L && i*j<=H)
                pSiz.pb({i,j});
        }
    }
    random_shuffle(pSiz.begin(), pSiz.end());

    for(auto s : pSiz){
        vector<Rect> tmp;
        for(int r=0; r<R; ++r){
            for(int c=0; c<C; ++c){
                if( val(r,c, r+s.first, c+s.second) ){
                    tmp.pb(Rect(r,c, r+s.first, c+s.second));
                }
            }
        }
        random_shuffle(tmp.begin(), tmp.end());
        pSol[p] = tmp;
    }
}

int size(int x1, int y1, int x2, int y2){
    return abs(x2-x1+1) * abs(y2-y1+1);
}

int sum(int x1, int y1, int x2, int y2){
    return SUM[x2+1][y2+1] + SUM[x1][y1] - SUM[x2+1][y1] - SUM[x1][y2+1];
}

bool val(int x1, int y1, int x2, int y2){
    int sz = size(x1, y1, x2, y2);
    int sm = sum(x1, y1, x2, y2)
    if( 2*L-sz <= sm && sm >= sz-2*L )
        return true;
    else
        return false;
}

int calc(){
    for(auto s : pSiz){
        
    }
}

int main(){
    cin>>R>>C>>L>>H;

    for(int i=0; i<R; ++i)
        cin>>a[i];

    preCalcSum();

    cout<<calc(0,0,R-1,C-1)<<"\n";

    return 0;
}
