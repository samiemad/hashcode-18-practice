#include <bits/stdc++.h>
using namespace std;

const char car[] = "MT";
int R, C, H, L;
char a[1002][1002];
int sc,nn;
int main(int argc, char** argv){
	cin>>R>>C>>L>>H;
    for(int i=0; i<R; ++i)
        cin>>a[i];

	sc=0;nn=R*C;

	ifstream sin = ifstream(argv[1]);
	int n;
	sin>>n;
	sin.ignore();
	for(int i=0; i<n; ++i){

		int x1,x2,y1,y2;
		sin>>x1>>y1>>x2>>y2;
		int sum[2] ;
		sum[0]=sum[1]=0;
		for(int ln=x1;ln<=x2;ln++)
			for(int cl=y1;cl<=y2;cl++)
				if(a[ln][cl]=='M')
					sum[0]++;
				else sum[1]++;
		int area=(x2-x1+1)*(y2-y1+1);
		
		if( sum[0] <L||sum[1]<L ||area>H ){
			cerr<<"INVALID\n";
			cerr<<"sum M= "<<sum[0]<<"sum T= "<<sum[1]<<" area = "<<area<<"\n";
			return 1;
		}	
		sc+=area;

	}
	
	double score = 1000.0 * sc / nn;
	cout<<score;

	return 0;
}
