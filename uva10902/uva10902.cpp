#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct point{
	double x,y;
};
bool check[100001];
vector<struct point> P;
bool cross(struct point,struct point,struct point,struct point);
int main(){
	int cases;
	while(scanf("%d",&cases) && cases){
		memset(check,true,sizeof(check));
		P.clear();
		for(int i=0;i<cases;i++){
			struct point tmp1,tmp2;
			scanf("%lf%lf%lf%lf",&tmp1.x,&tmp1.y,&tmp2.x,&tmp2.y);
			P.push_back(tmp1);
			P.push_back(tmp2);
//			for(int j=i;j>0;j--){
//				if(cross(P[i*2],P[i*2+1],P[(j-1)*2],P[(j-1)*2+1])){
//					check[j-1] = false;
//				}
//				else if(cross(P[i*2+1],P[i*2],P[(j-1)*2],P[(j-1)*2+1])){
//					check[j-1] = false;
//				}
//			}
		}
		for(int i=0;i<cases;i++){
			for(int j=i+1;j<cases;j++){
				if(cross(P[i*2],P[i*2+1],P[j*2],P[j*2+1])){
					check[i]=false;
					break;
				}
			}
		}
		printf("Top sticks:");
		for(int i=0;i<cases;i++){
			if(check[i]){
				printf(" %d",i+1);
				if(i!=cases-1)
					printf(",");
				else
					printf(".\n");
			}
		}
	}
}

bool cross(point P1,point P2,point P3,point P4){
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
		return true;
	else
		return false;
}

