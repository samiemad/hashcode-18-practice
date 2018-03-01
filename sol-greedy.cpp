#include <bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
#define mt make_tuple
typedef pair<int,int> ii;

int R, C, F, N, B, T;
int sc,nn;
struct ride{
    int a,b,x,y,s,f;
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

int cmp(const ride& a, const ride& b){
    return mt(a.f,a.s,-dist(a)) < mt(b.f,b.s,-dist(b));
}

int main(int argc, char** argv){
    cin>>R>>C>>F>>N>>B>>T;
    for (int i=0;i<N;i++)
        cin>>rides[i].a>>rides[i].b>>rides[i].x>>rides[i].y>>rides[i].s>>rides[i].f;

    sort(rides, rides+N, cmp);

    cerr<<rides[0].a<<","<<rides[0].b<<","<<rides[0].x<<","<<rides[0].y<<","<<rides[0].s<<","<<rides[0].f<<"\n";

    for(int i=0; i<N; ++i){
        ride &r = rides[i];
        int c = nearsetCar(r.a,r.b);
        if( c != -1 ){
            sol[c].pb(i);
            cars[c].t = calc(c, i);
            cars[c].x = r.x;
            cars[c].y = r.y;
        }
    }
    for(int i=0; i<F; ++i){
        cout<<i;
        for(auto x:sol[i])
            cout<<" "<<x;
        cout<<"\n";
    }

    return 0;
}
