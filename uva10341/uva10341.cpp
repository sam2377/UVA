#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
long double p,q,r,s,t,u;
long double cal(long double a){
		return (p*exp(-a)+q*sin(a)+r*cos(a)+s*tan(a)+t*a*a+u);
}
int main(){
	while(scanf("%Lf%Lf%Lf%Lf%Lf%Lf",&p,&q,&r,&s,&t,&u)!=EOF){
		long double min=0.0, max=1.0,mid;
		for(int i=0;i<100;i++){
			mid=(min+max)/2;
			if(cal(mid)>0) min = mid;
			else max=mid;
		}
		if(fabs(cal(mid)-0)> 1e-10) printf("No solution\n");
		else printf("%.4Lf\n",mid);
	}
}
