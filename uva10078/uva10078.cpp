#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
struct point{
	int x,y;
	bool operator < (const point &a) const{
		if(x==a.x) return y < a.y;
		return x < a.x;
	}
}P[1001];
struct point ans[1001];
int cross(struct point,struct point,struct point);
int main(){
	int num;
	bool check;
	while(scanf("%d",&num)&&num){
		check = false;
		for(int i=0;i<num;i++){
			cin >> P[i].x >> P[i].y;
		}
		sort(P,P+num);
		int m=0;
		for(int i=0;i<num;i++){
			while(m>=2 && cross(ans[m-2],ans[m-1],P[i])<0) m--;
			ans[m++] = P[i];
		}
		for(int i=num-2,t=m+1;i>=0;i--){
			while(m>=t && cross(ans[m-2],ans[m-1],P[i])<0) m--;
			ans[m++] = P[i];
		}
		m--;
//		for(int i=0;i<m;i++){
//			printf("%d %d\n",ans[i].x,ans[i].y);
//		}
//		printf("\n\n");
		if(m!=num) check = true;
		if(check) printf("Yes\n");
		else		printf("No\n");
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
