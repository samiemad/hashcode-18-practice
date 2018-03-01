#include <bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
#define mt make_tuple
typedef pair<int,int> ii;

int R, C, F, N, B, T;
int sc,nn;
struct ride{
    int a,b,x,y,s,f,idx;
};
struct car{
    int x,y,t;
};
ride rides[10001];
car cars[1003];
vector<int> sol[1003];

int dist(const ride& r){
    return abs(r.a-r.x) + abs(r.b-r.y);
}
int dist(int x, int y, int xx, int yy){
    return abs(x-xx) + abs(y-yy);
}

int cmp(const ride& a, const ride& b){
    return mt(a.f,a.s,-dist(a)) < mt(b.f,b.s,-dist(b));
}

int calcWeight(const car& c, const ride& r){
    int t = max( c.t + dist(c.x, c.y, r.a, r.b), r.s ) + dist(r);
    if( t < r.f )
        return t;
    else
        return 1e9;
}

int nearsetCar(int id){
    const ride& r = rides[id];
    int c=-1;
    int mn = 1e9;
    for(int i=0; i<F; ++i){
        int clc = calcWeight(cars[i], r);
        if( mn > clc ){
            mn = clc;
            c = i;
        }
    }
    return c;
}

int main(int argc, char** argv){
    cin>>R>>C>>F>>N>>B>>T;
    for (int i=0;i<N;i++){
        cin>>rides[i].a>>rides[i].b>>rides[i].x>>rides[i].y>>rides[i].s>>rides[i].f;
        rides[i].idx = i;
    }

    sort(rides, rides+N, cmp);

    for(int i=0; i<N; ++i){
        ride &r = rides[i];
        int c = nearsetCar(i);
        if( c != -1 ){
            sol[c].pb(r.idx);
            cars[c].t = calcWeight(cars[c], r);
            cars[c].x = r.x;
            cars[c].y = r.y;
        }
    }
    int t=0;
    for(int i=0; i<F; ++i){
        t += sol[i].size();
        cout<<sol[i].size();
        for(auto x:sol[i])
            cout<<" "<<x;
        cout<<"\n";
    }
    cerr<< 100.0 * t / N <<"% rides taken\n";

    return 0;
}
