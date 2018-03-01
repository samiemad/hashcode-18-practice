#include <bits/stdc++.h>
using namespace std;
int R,C,F,N,B,T;
int sc,nn;

struct pnt{
	int x,y;
};

struct ride{
	int s,f;
	pnt St,Fn;
};

int manhatten(pnt a,pnt b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
ride rides[10001];
int main(int argc, char** argv){
	cin>>R>>C>>F>>N>>B>>T;
	nn=0;
	for (int i=0;i<N;i++){
		cin>>rides[i].St.x>>rides[i].St.y>>rides[i].Fn.x>>rides[i].Fn.y>>rides[i].s>>rides[i].f;
		nn+=B+manhatten(rides[i].St,rides[i].Fn);
	}

	sc=0;

	ifstream sin = ifstream(argv[1]);
	

	for(int i=0; i<F; ++i){
		int num,curRideId;
		sin>>num;
		int curT=0;
		pnt Cur;Cur.x=Cur.y=0;
		for (int j=0;j<num;j++){
			sin>>curRideId;
			ride curRide=rides[curRideId];
			int distToStart=manhatten(Cur,curRide.St) ;// abs(curX-rides[curRide].a)+abs(curY-rides[curRide].b);
			int timeToStart=curT+distToStart;
			if(timeToStart<=curRide.s)
				sc+=B;
			int tripDist=manhatten(curRide.Fn,curRide.St);
			int startingT=max(curRide.s,timeToStart);
			int finshingT=startingT+tripDist;
			if(finshingT>curRide.f)
				cerr<<"invalid: curRide "<<curRideId<<" :vih "<<i<<" is finishing after its finishing time\n";
			else
			 	sc+=manhatten(curRide.St,curRide.Fn);
			curT=finshingT;
			Cur=curRide.Fn;
		}
	}
	cout<<sc;

	return 0;
}