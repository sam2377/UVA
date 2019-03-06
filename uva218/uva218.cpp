#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct point{
	double x,y;
	bool operator < (const point &a) const{
		if(x==a.x) return y < a.y;
		return x < a.x;
	}
}P[10001];
double cross(struct point,struct point,struct point);
struct point ans[10001];
int main(){
	int num,cases=1;
	while(cin >> num && num){
		double ln = 0;
		if(cases!=1) printf("\n");
		for(int i=0;i<num;i++){
			cin >> P[i].x >> P[i].y;
		}
		sort(P,P+num);
//		for(int i=0;i<num;i++){
//			cout << P[i].x << " " << P[i].y << endl;
//		}
		int m = 0;
		for(int i=0;i<num;i++){
			while(m>=2 && cross(ans[m-2],ans[m-1],P[i]) <=0 ) m--;
			ans[m++] = P[i];
		}
		for(int i=num-2,t=m+1;i>=0;i--){
			while(m>=t && cross(ans[m-2],ans[m-1],P[i]) <=0 ) m--;
			ans[m++] = P[i];
		}
		m--;
		printf("Region #%d:\n",cases++);
		for(int i=m;i>=0;i--){
			printf("(%.1lf,%.1lf)",ans[i].x,ans[i].y);
			if(i!=0) printf("-");
			else printf("\n");
			if(i!=m){
				ln += sqrt(pow((ans[i].x-ans[i+1].x),2) + pow((ans[i].y-ans[i+1].y),2));
			}
		}
		printf("Perimeter length = %.2lf\n",ln);
	}
	return 0;
}
double cross(point P1,point P2,point P3){
	double x1,y1,x2,y2,x3,y3;
	x1 = P1.x;
	y1 = P1.y;
	x2 = P2.x;
	y2 = P2.y;
	x3 = P3.x;
	y3 = P3.y;
	return ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
}


