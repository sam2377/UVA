#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct point{
	int x,y;
	bool operator < (const point &a) const{
		if(x==a.x) return y < a.y;
		return x > a.x;
	}
}P[1001];
int cross(struct point,struct point,struct point);
struct point ans[1001];
int main(){
	int num;
	string cases;
	cin.ignore();
	while(1){
			cin.ignore();
			getline(cin,cases);
			int cnt = 0;
			cout << cases;
			printf(" convex hull:\n");
			while(cin >> cases){
				if(cases[0]!='P') break;
				scanf("%d",&num);
				for(int i=0;i<num;i++){
					scanf("%d%d",&P[cnt].x,&P[cnt].y);
					cnt++;
				}
			}
			sort(P,P+cnt);
			int m = 0;
			for(int i=0;i<cnt;i++){
				if(i>=1 && P[i].x==P[i-1].x && P[i].y==P[i-1].y) continue;
					while(m>=2 && cross(ans[m-2],ans[m-1],P[i])<0 ) m--;
					ans[m++] = P[i];
			}
			for(int i=cnt-2,t=m+1;i>=0;i--){
				if(i>=1 && P[i].x==P[i-1].x && P[i].y==P[i-1].y) continue;
					while(m>=t && cross(ans[m-2],ans[m-1],P[i])<0 ) m--;
					ans[m++] = P[i];
			}
			m--;
			for(int i=0;i<m;i++){
				printf(" (%d,%d)",ans[i].x,ans[i].y);
				if(i==m-1) printf("\n");
			}
			if(cases[0]=='E') break;
	}
	return 0;
}

int cross(point P1,point P2,point P3){
	int x1,y1,x2,y2,x3,y3;
	x1 = P1.x;
	y1 = P1.y;
	x2 = P2.x;
	y2 = P2.y;
	x3 = P3.x;
	y3 = P3.y;
	return ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
}
