#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
struct point{
	double x,y;
};
bool check;
void cross(struct point,struct point,struct point,struct point);
int main(){
	int cases;
	cin >> cases;
	while(cases--){
		struct point p1,p2,p3,p4,start,end;
		double xs,ys,xe,ye,xl,yt,xr,yb,tmp;
		cin >> xs >> ys >> xe >> ye >> xl >> yt >> xr >> yb;
		if(xl > xr){
			tmp = xr;
			xr = xl;
			xl = tmp;
		}
		if(yb > yt){
			tmp = yt;
			yt = yb;
			yb = tmp;
		}
		start.x = xs;
		start.y = ys;
		end.x = xe;
		end.y = ye;
		p1.x = xl;
		p1.y = yt;
		p2.x = xr;
		p2.y = yt;
		p3.x = xr;
		p3.y = yb;
		p4.x = xl;
		p4.y = yb;
		check = false;
		cross(p1,p2,start,end);
		cross(p2,p3,start,end);
		cross(p3,p4,start,end);
		cross(p4,p1,start,end);
		if(start.x <= xr && start.x >=xl && start.y <= yt && start.y >=yb && end.x <= xr && end.x >= xl && end.y >= yb && end.y <= yt) check =true;
		if(check) printf("T\n");
		else	printf("F\n");
	}
}

void cross(point P1,point P2,point P3,point P4){
	double x1,y1,x2,y2,x3,y3,x4,y4;
	x1 = P1.x;
	y1 = P1.y;
	x2 = P2.x;
	y2 = P2.y;
	x3 = P3.x;
	y3 = P3.y;
	x4 = P4.x;
	y4 = P4.y;
	if(((((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1))*((x2-x1)*(y4-y1)-(y2-y1)*(x4-x1))) < 0 && (((x4-x3)*(y1-y3)-(y4-y3)*(x1-x3))*((x4-x3)*(y2-y3)-(x2-x3)*(y4-y3))) < 0) || ((((x4-x3)*(y2-y3)-(x2-x3)*(y4-y3))==0) && ((x2<=max(x3,x4)) && (x2>=min(x3,x4)) && (y2>=min(y3,y4)) && (y2<=max(y3,y4))))) 
	check = true;
}

