#include <bits/stdc++.h>
using namespace std;
int R,C,F,N,B,T;
int sc,nn;

struct pnt{
	int x,y;
}

struct ride{
	int s,f;
	pnt St,Fn;
}

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
		int num,curRide;
		sin>>num;
		int curT=0;
		pnt Cur;Cur.X=Cur.Y=0;
		for (int j=0;j<num;j++){
			sin>>curRide;
			int distToStart=manhatten(Cur,rides[curRide].St) ;// abs(curX-rides[curRide].a)+abs(curY-rides[curRide].b);
			int timeToStart=curT+distToStart;
			if(timeToStart<=rides[curRide].s)
				sc+=B;
			int tripDist=manhatten(rides[curRide].Fn,rides[curRide].St);
			int startingT=max(rides[curRide].s,timeToStart);
			int finshingT=startingT+tripDist;
			if(finshingT>rides[curRide].f)
				cout<<"invalid: curRide "<<curRide<<" :vih "<<vih<<" is finishing after its finishing time\n";
			else
			 	sc+=manhatten(rides[curRide]);
			curT=finshingT;
			Cur=rides[vih].Fn;
		}
		
		if(curT>T){
			cout<<"your"<<i<<"car has used "<< curT<<"minuets,and your just have "<<T<<"minuets\n";
		}
	}
	double score = 1000.0 * sc / nn;
	cout<<score;

	return 0;
}
