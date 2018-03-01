#include <bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
typedef pair<int,int> ii;

int R, C, F, N, B, T;
int sc,nn;
struct ride{
    int a,b,x,y,s,f;
}
ride rides[10001];

int cmp(const ride& a, const ride& b){
    return a.f < b.f;
}

int main(int argc, char** argv){
    cin>>R>>C>>F>>N>>B>>T;
    for (int i=0;i<N;i++)
        cin>>rides[i].a>>rides[i].b>>rides[i].x>>rides[i].y>>rides[i].s>>rides[i].f;

    sort(rides, rides+N, cmp);

    cout<<rides[0].a<<","<<rides[0].b<<","<<rides[0].x<<","<<rides[0].y<<","<<rides[0].s<<","<<rides[0].f<<"\n";

    return 0;
}
